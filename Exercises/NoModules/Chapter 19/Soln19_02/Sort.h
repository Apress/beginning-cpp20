// Sort.h

#ifndef SORT_H
#define SORT_H

#include <cstddef>    // for size_t
#include <utility>    // for std::swap()
#include <vector>

// The top level sort() template with one parameter calls the sort() template with three parameters
template<typename T, typename Compare>
void sort(std::vector<T>& data, Compare compare, size_t start, size_t end);

// Sort all vector elements
template<typename T, typename Compare>
void sort(std::vector<T>& values, Compare compare)
{
  if (!values.empty())
    sort(values, compare, 0, values.size() - 1);
}

// Swap two vector elements
template<typename T>
void swap(std::vector<T>& data, size_t first, size_t second)
{
  std::swap(data[first], data[second]);
}

// Sort a range of vector elements
template<typename T, typename Compare>
void sort(std::vector<T>& data, Compare compare, size_t start, size_t end)
{
  // Start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;

  // Choose middle value to partition set
  swap(data, start, (start + end) / 2);       // Swap middle value with start
 
  // Check data against chosen value
  size_t current{ start };                    // The index of the last element less than the chosen element (after partitioning)
  for (size_t i{ start + 1 }; i <= end; ++i)
  {
    if (compare(data[i], data[start]))        // Is value less than chosen word?
      swap(data, ++current, i);               // Yes, so swap to the left
  }

  swap(data, start, current);                 // Swap the chosen value with last in

  if (current > start) sort(data, compare, start, current - 1); // Sort left subset if exists
  if (end > current + 1) sort(data, compare, current + 1, end); // Sort right subset if exists
}


#endif // SORT_H