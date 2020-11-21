export module array;

import <stdexcept>;                        // For standard exception types
import <string>;                           // For std::to_string()
import <utility>;                          // For std::as_const()
import <concepts>;

export template <typename T> requires std::default_initializable<T> && std::destructible<T>
class Array
{
public:
  Array();                                  
  explicit Array(size_t size);              
  ~Array();                                 
  Array(const Array& array) requires std::copyable<T>;
  Array& operator=(const Array& rhs) requires std::copyable<T>;
  Array(Array&& array) noexcept requires std::movable<T>;
  Array& operator=(Array&& rhs) noexcept requires std::movable<T>;
  void swap(Array& other) noexcept;        
  T& operator[](size_t index);             
  const T& operator[](size_t index) const; 
  size_t getSize() const { return m_size; }
  void push_back(T element) requires std::movable<T>;

private:
  T* m_elements;    // Array of type T
  size_t m_size;    // Number of array elements
};

// Forwarding default constructor template
template <typename T> requires std::default_initializable<T> && std::destructible<T>
Array<T>::Array() 
  : Array{0}
{}

// Constructor template
template <typename T> requires std::default_initializable<T> && std::destructible<T>
Array<T>::Array(size_t size) 
  : m_elements {new T[size] {}}, m_size {size}
{}

// Copy constructor template
template <typename T> requires std::default_initializable<T> && std::destructible<T>
Array<T>::Array(const Array& array) requires std::copyable<T> 
  : Array{array.m_size}
{
  for (size_t i {}; i < m_size; ++i)
    m_elements[i] = array.m_elements[i];
}

// Move constructor template
template <typename T> requires std::default_initializable<T> && std::destructible<T>
Array<T>::Array(Array&& moved) noexcept requires std::movable<T>
  : m_size{moved.m_size}, m_elements{moved.m_elements}
{
  moved.m_elements = nullptr; // Otherwise destructor of moved would delete[] m_elements!
}

// Destructor template
template <typename T> requires std::default_initializable<T> && std::destructible<T>
Array<T>::~Array() { delete[] m_elements; }

// const subscript operator template
template <typename T> requires std::default_initializable<T> && std::destructible<T>
const T& Array<T>::operator[](size_t index) const
{
  if (index >= m_size)
    throw std::out_of_range {"Index too large: " + std::to_string(index)};
  return m_elements[index];
}

// Non-const subscript operator template in terms of const one
// Uses the 'const-and-back-again' idiom
template <typename T> requires std::default_initializable<T> && std::destructible<T>
T& Array<T>::operator[](size_t index)
{
  return const_cast<T&>(std::as_const(*this)[index]);
}

// Template for exception-safe copy assignment operators
// (expressed in terms of copy constructor and swap member)
template <typename T> requires std::default_initializable<T> && std::destructible<T>
Array<T>& Array<T>::operator=(const Array& rhs) requires std::copyable<T>
{
  Array<T> copy{ rhs }; // Copy...       (could go wrong and throw an exception)
  swap(copy);           // ... and swap! (noexcept)
  return *this;
}

// Move assignment operator template
template <typename T> requires std::default_initializable<T> && std::destructible<T>
Array<T>& Array<T>::operator=(Array&& rhs) noexcept requires std::movable<T>
{
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
template <typename T> requires std::default_initializable<T> && std::destructible<T>
void Array<T>::swap(Array& other) noexcept
{
  std::swap(m_elements, other.m_elements); // Swap two pointers
  std::swap(m_size, other.m_size);         // Swap the sizes
}

// Swap non-member function template (optional)
export template <typename T> requires std::default_initializable<T> && std::destructible<T>
void swap(Array<T>& one, Array<T>& other) noexcept
{
  one.swap(other);     // Forward to public member function
}

// push_back() overload for lvalue references
template <typename T> requires std::default_initializable<T> && std::destructible<T>
void Array<T>::push_back(T element) requires std::movable<T>
{
  Array<T> newArray{m_size + 1};      // Allocate a larger Array<>
  for (size_t i{}; i < m_size; ++i)   // Move all existing elements...
    newArray[i] = std::move(m_elements[i]);

  newArray[m_size] = std::move(element); // Move the new one (could itself be a copy already)...

  swap(newArray);                     // ... and swap!
}

