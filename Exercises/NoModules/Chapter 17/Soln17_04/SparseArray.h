// SparseArray class template definition
// Note the use of the find() helper function and the const-and-back-again idiom to minimize code duplication

#ifndef SPARSEARRAY_H
#define SPARSEARRAY_H

#include "Pair.h"
#include <vector>
#include <string>       // For std::to_string()
#include <utility>      // For std::as_const()
#include <stdexcept>

template<typename T>
class SparseArray
{
public:
  T& operator[](size_t index);              // Subscript operator (creates default-constructed value if no value exists for the given index)
  T& at(size_t index);                      // Access function (throws std::out_of_range if no value exists for the given index)
  const T& at(size_t index) const;          // const overload of at()
  bool element_exists_at(size_t index) const;  // Return true iff an element exists at the given index

private:
  T* find(size_t index);                    // Helper function (returns nullptr if no value exists for the given index)
  const T* find(size_t index) const;
  
  std::vector<Pair<size_t, T>> m_values;
};

template<typename T>
T& SparseArray<T>::operator[](size_t index)
{
  if (auto* found{ find(index) }; found)   // Using C++17 initialization statements for if statement 
  {                                        // (see at() function for common, traditional equivalent)
	  return *found;
  }
  else
  {
    m_values.push_back({ index, T{} });    // Or push_back(Pair{...}), or push_back(Pair<size_t, T>{...})
    return m_values.back().second;         // Remember: std::vector<>::back() returns a reference to its last element
  }
}

template<typename T>
const T& SparseArray<T>::at(size_t index) const
{
  const auto* found{ find(index) };
  if (found)
  {
	  return *found;
  }
  else
  {
    throw std::out_of_range{"No value exists at index " + std::to_string(index)};
  }
}

template<typename T>
T& SparseArray<T>::at(size_t index)
{
  return const_cast<T&>(std::as_const(*this).at(index));
}

template<typename T>
bool SparseArray<T>::element_exists_at(size_t index) const
{
  return find(index) != nullptr;
}

template<typename T>
const T* SparseArray<T>::find(size_t index) const
{
  for (auto& pair : m_values)
  {
    if (pair.first == index)
      return &pair.second;
  }
  return nullptr;
}

template<typename T>
T* SparseArray<T>::find(size_t index)
{
  return const_cast<T*>(std::as_const(*this).find(index));
}

#endif //SPARSEARRAY_H