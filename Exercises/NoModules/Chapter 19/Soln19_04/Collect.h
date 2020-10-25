#ifndef COLLECT_H
#define COLLECT_H

#include <vector>

template <typename T, typename Predicate>
std::vector<T> collect(const std::vector<T>& values, Predicate predicate)
{
  std::vector<T> result;
  
  for (auto& value : values)
    if (predicate(value))
      result.push_back(value);
  
  return result;
}

#endif // COLLECT_H