export module array;

import <stdexcept>;                        // For standard exception types
import <string>;                           // For to_string()
import <utility>;                          // For std::as_const()

export template <typename T, int startIndex>
class Array
{
public:
  explicit Array(size_t size);              // Constructor
  ~Array();                                 // Destructor
  Array(const Array& array);                // Copy constructor  
  Array& operator=(const Array& rhs);       // Assignment operator
  void swap(Array& other) noexcept;         // noexcept swap() function
  T& operator[](int index);                 // Subscript operator
  const T& operator[](int index) const;     // Subscript operator-const arrays
  size_t getSize() const { return m_size; } // Accessor for size

private:
  T* m_elements;   // Array of type T
  size_t m_size;   // Number of array elements
};

// Constructor template
template <typename T, int startIndex>
Array<T, startIndex>::Array(size_t size) : m_elements{ new T[size] {} }, m_size{ size }
{}

// Copy constructor template
template <typename T, int startIndex>
Array<T, startIndex>::Array(const Array& array) : Array{array.m_size}
{
  for (size_t i {}; i < m_size; ++i)
    m_elements[i] = array.m_elements[i];
}

// Destructor template
template <typename T, int startIndex>
Array<T, startIndex>::~Array() { delete[] m_elements; }

// const subscript operator template (improved readability!)
template <typename T, int startIndex>
const T& Array<T, startIndex>::operator[](int index) const
{
  // Subtract startIndex to obtain the actual index into the m_elements array.
  // If startIndex is 0, conventional 0-based array indexing is used.
  const int actualIndex{ index - startIndex };

  if (actualIndex < 0)
    throw std::out_of_range {"Index too small: " + std::to_string(index)};

  if (actualIndex >= m_size)
    throw std::out_of_range {"Index too large: " + std::to_string(index)};

  return m_elements[actualIndex];
}

// Non-const subscript operator template in terms of const one
// Uses the 'const-and-back-again' idiom
template <typename T, int startIndex>
T& Array<T, startIndex>::operator[](int index)
{
  return const_cast<T&>(std::as_const(*this)[index]);
}

// Template for exception-safe copy assignment operators
// (expressed in terms of copy constructor and swap member)
template <typename T, int startIndex>
Array<T, startIndex>& Array<T, startIndex>::operator=(const Array& rhs)
{
  Array<T> copy{ rhs }; // Copy...       (could go wrong and throw an exception)
  swap(copy);           // ... and swap! (noexcept)
  return *this;
}

// Swap member function template
template <typename T, int startIndex>
void Array<T, startIndex>::swap(Array& other) noexcept
{
  std::swap(m_elements, other.m_elements); // Swap two pointers
  std::swap(m_size, other.m_size);         // Swap the sizes
}

// Swap non-member function template (can only swap arrays with identical startIndex)
export template <typename T, int startIndex>
void swap(Array<T, startIndex>& one, Array<T, startIndex>& other) noexcept
{
  one.swap(other);     // Forward to public member function
}

