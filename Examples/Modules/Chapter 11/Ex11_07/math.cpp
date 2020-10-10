module;
#include <cmath>    // For std::pow(), std::sqrt(), ...
module math;

import <limits>;   // For std::numeric_limits<double>::quiet_NaN()
import <vector>;   // For std::numeric_limits<double>::quiet_NaN()

void quicksort(std::vector<double>& data); // See Chapter 8

// Option 1: define in nested namespace block (compact syntax)
namespace math::averages
{
  double arithmetic_mean(std::span<const double> data)
  {
    // The arithmetic mean, the most commonly used average, 
    // is defined as the sum of all elements divided by the number of elements.
    double sum {};
    for (auto value : data)
      sum += value;
    
    return data.empty() 
      ? std::numeric_limits<double>::quiet_NaN() // Or std::nan("")
      : sum / data.size();
  }
}

// Option 2: define in nested namespace blocks
namespace math
{
  namespace averages
  {
    double geometric_mean(std::span<const double> data)
    {
      // The geometric mean of n elements
      // is defined as the n-th root of the product of all n elements
      double product{ 1 };
      for (auto value : data)
        product *= value;

      return data.empty()
        ? std::numeric_limits<double>::quiet_NaN() 
        : std::pow(product, 1.0 / data.size());
    }
  }
}

// Option 3: define using fully qualified function name
double math::averages::rms(std::span<const double> data)
{ 
  // The RMS or root mean square is defined as 
  // square root of the arithmetic mean of the squares of the elements.
  double sum_squares{};
  for (auto value : data)
    sum_squares += square(value);

  return data.empty()
    ? std::numeric_limits<double>::quiet_NaN() // Or std::nan("")
    : std::sqrt(sum_squares / data.size());
}

// Option 4: define using qualified name in outer namespace block
namespace math
{
  double averages::median(std::span<const double> data)
  {
    // The median of an odd number of elements is the value 
    // that appears in the middle position of these elements when they are sorted.
    // The median of an even number of elements is typically
    // defined as the mean of the two middle elements in a sorted range.

    // We cannot sort the data span itself, because it's elements are const.
    // Therefore, we first copy the const input data to be able to sort it
    std::vector<double> sorted;

    // Use range-based for loop to copy the input data.
    // See Chapter 20 for built-in means of copying a data range.
    for (auto value : data)
      sorted.push_back(value);

    // See Chapter 20 for built-in means of (partially) sorting data
    quicksort(sorted);

    const size_t mid = data.size() / 2;
    return data.empty() ? std::numeric_limits<double>::quiet_NaN() // Or std::nan
         : data.size() % 2 == 1 ? sorted[mid]
         : (sorted[mid - 1] + sorted[mid]) / 2;
  }
}

void quicksort(std::vector<double>& data, size_t start, size_t end);
void quicksort(std::vector<double>& data)
{
  if (!data.empty())
    quicksort(data, 0, data.size() - 1);
}

void quicksort(std::vector<double>& data, size_t start, size_t end)
{
  // start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;

  // Choose middle value to partition set, 
  // and move it to the front of the current range
  std::swap(data[start], data[(start + end) / 2]);
  
  // Compare all other values against chosen value at index start
  size_t current{ start };
  for (size_t i{ start + 1 }; i <= end; i++)
  {
    if (data[i] < data[start]) // Is the value less than chosen value?
      std::swap(data[++current], data[i]); // Yes, so swap to the left
  }

  std::swap(data[start], data[current]); // Swap chosen and last swapped words

  if (current > start) quicksort(data, start, current - 1); // Sort left subset if exists
  if (end > current + 1) quicksort(data, current + 1, end); // Sort right subset if exists
}
