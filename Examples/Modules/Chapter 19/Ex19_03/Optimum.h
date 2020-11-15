// Optimum.h - a function template to determine the optimum element in a given vector
#ifndef OPTIMUM_H
#define OPTIMUM_H

#include <cstddef>	// For std::size_t	(required here by some compilers)
#include <vector>

template <typename T, typename Comparison>
const T* findOptimum(const std::vector<T>& values, Comparison compare)
{
  if (values.empty()) return nullptr;

  const T* optimum{ &values[0] };
  for (size_t i {1}; i < values.size(); ++i)
  {
    if (compare(values[i], *optimum))
      optimum = &values[i];
  }
  return optimum;
}

#endif