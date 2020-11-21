export module collect;

import <vector>;

export template <typename T, typename Predicate>
std::vector<T> collect(const std::vector<T>& values, Predicate predicate)
{
  std::vector<T> result;
  
  for (auto& value : values)
    if (predicate(value))
      result.push_back(value);
  
  return result;
}
