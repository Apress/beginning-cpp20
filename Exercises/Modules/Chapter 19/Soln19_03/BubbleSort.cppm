export module sort.bubble;

import <utility>;    // for std::swap()
import <vector>;

// The sorting algorithm exported by this module
export template<typename T, typename Compare>
void bubbleSort(std::vector<T>& data, Compare compare);

// Utility to swap two vector elements
template<typename T>
void swap(std::vector<T>& data, size_t first, size_t second)
{
  std::swap(data[first], data[second]);
}

template<typename T, typename Compare>
void bubbleSort(std::vector<T>& data, Compare compare)
{
  if (data.empty())
    return;

  while (true)
  {
    bool swapped{ false };    // Becomes true when not all values are in order
    for (size_t i {}; i < data.size() - 1; ++i)
    {
      if (compare(data[i+1], data[i]))  // Out of order so swap them
      {
        swap(data, i, i+1);
        swapped = true;
      }
    }
	
    if (!swapped)   // If there were no swaps
      break;        // ...they are in order...
  }                 // ...otherwise, go round again.
}	
