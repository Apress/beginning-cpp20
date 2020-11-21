export module array;

import <stdexcept>;                        // For standard exception types
import <string>;                           // For std::to_string()
import <utility>;                          // For std::as_const()
import <iostream>;

/*
// Original template based on type traits and some mild template meta-programming
template<class T>
std::conditional_t<std::is_nothrow_move_assignable_v<T>, T&&, const T&>
move_assign_if_noexcept(T& x) noexcept
{
  return std::move(x);
}
*/

// A straightforward concept with a single compound requirement
template <typename T>
concept NoThrowMoveAssignable =
  requires (T left, T right) { { left = std::move(right) } noexcept -> std::same_as<T&>; };

// By default: return lvalue reference (will result in x being copied)
// (Note: this default move_assign_if_noexcept() template in itself is noexcept, 
//  the copy assignment that generally follows is not...)
auto& move_assign_if_noexcept(auto& x) noexcept { return x; }

// Specialization that moves if possible without throwing
// Uses abbreviated template syntax with a type constraint on auto)
auto&& move_assign_if_noexcept(NoThrowMoveAssignable auto& x) noexcept { return std::move(x); }


export template <typename T>
class Array
{
public:
  Array();                                  // Default constructor
  explicit Array(size_t size);              // Constructor
  ~Array();                                 // Destructor
  Array(const Array& array);                // Copy constructor
  Array(Array&& array) noexcept;            // Move constructor
  Array& operator=(const Array& rhs);       // Copy assignment operator
  Array& operator=(Array&& rhs) noexcept;   // Move assignment operator
  void swap(Array& other) noexcept;         // Swap member function
  T& operator[](size_t index);              // Subscript operator
  const T& operator[](size_t index) const;  // Subscript operator-const arrays
  size_t getSize() const { return m_size; } // Accessor for m_size
  void push_back(T element);                // Copy or move element to the back of the array

private:
  T* m_elements;    // Array of type T
  size_t m_size;    // Number of array elements
};

// Forwarding default constructor template
template <typename T>
Array<T>::Array() : Array{0}
{}

// Constructor template
template <typename T>
Array<T>::Array(size_t size) : m_elements {new T[size] {}}, m_size {size}
{}

// Copy constructor template
template <typename T>
Array<T>::Array(const Array& array) : Array{array.m_size}
{
  std::cout << "Array of " << m_size << " elements copied" << std::endl;
  for (size_t i {}; i < m_size; ++i)
    m_elements[i] = array.m_elements[i];
}

// Move constructor template
template <typename T>
Array<T>::Array(Array&& moved) noexcept
  : m_size{moved.m_size}, m_elements{moved.m_elements}
{
  std::cout << "Array of " << m_size << " elements moved" << std::endl;
  moved.m_elements = nullptr; // Otherwise destructor of moved would delete[] m_elements!
}

// Destructor template
template <typename T>
Array<T>::~Array() { delete[] m_elements; }

// const subscript operator template
template <typename T>
const T& Array<T>::operator[](size_t index) const
{
  if (index >= m_size)
    throw std::out_of_range {"Index too large: " + std::to_string(index)};
  return m_elements[index];
}

// Non-const subscript operator template in terms of const one
// Uses the 'const-and-back-again' idiom
template <typename T>
T& Array<T>::operator[](size_t index)
{
  return const_cast<T&>(std::as_const(*this)[index]);
}

// Template for exception-safe copy assignment operators
// (expressed in terms of copy constructor and swap member)
template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
  Array<T> copy{ rhs }; // Copy...       (could go wrong and throw an exception)
  swap(copy);           // ... and swap! (noexcept)
  return *this;
}

// Move assignment operator template
template <typename T>
Array<T>& Array<T>::operator=(Array&& rhs) noexcept
{
  std::cout << "Array of " << rhs.m_size << " elements moved (assignment)" << std::endl;

  if (&rhs != this)            // prevent trouble with self-assignments
  {
    delete[] m_elements;       // delete[] all existing elements

    m_elements = rhs.m_elements; // copy the elements pointer and the size
    m_size = rhs.m_size;

    rhs.m_elements = nullptr;  // make sure rhs does not delete[] m_elements
  }
  return *this;                // return lhs
}

// Swap member function template
template <typename T>
void Array<T>::swap(Array& other) noexcept
{
  std::swap(m_elements, other.m_elements); // Swap two pointers
  std::swap(m_size, other.m_size);         // Swap the sizes
}

// Swap non-member function template (optional)
export template <typename T>
void swap(Array<T>& one, Array<T>& other) noexcept
{
  one.swap(other);     // Forward to public member function
}

// push_back() overload for lvalue references
template <typename T>
void Array<T>::push_back(T element)  // Pass by value (copy of lvalue, or moved rvalue!)
{
  Array<T> newArray{m_size + 1};     // Allocate a larger Array<>
  for (size_t i {}; i < m_size; ++i) // Move existing elements (copy if not noexcept)...
    newArray[i] = move_assign_if_noexcept(m_elements[i]);

  newArray[m_size] = move_assign_if_noexcept(element);  // Move (or copy) the new one...

  swap(newArray);                   // ... and swap!
}
