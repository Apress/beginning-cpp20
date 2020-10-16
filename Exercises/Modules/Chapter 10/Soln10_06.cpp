// Exercise 10-6 A Quicksort function template

#include <iostream>
#include <format>
#include <vector>

template <typename T>
void swap(std::vector<T>& data, size_t first, size_t second);
template <typename T>
void sort(std::vector<T>& data);
template <typename T>
void sort(std::vector<T>& data, size_t start, size_t end);
template <typename T>
void show(const std::vector<T>& data, size_t width = 5);

int main()
{
  std::vector<int> numbers{ -2, 4, -5, 6, 10, -40, 56, 4, 67, 45 };
  show(numbers);
  sort(numbers);
  std::cout << "\nSorted integers:\n";
  show(numbers);

  std::cout << "\nCharacters to be sorted:\n";
  std::vector<char> letters{ 'C', 'd', 'a', 'z', 't', 'S', 'p', 'm', 'D', 'f' };
  show(letters, 2);
  sort(letters);
  std::cout << "\nSorted characters:\n";
  show(letters, 2);

  std::cout << "\nFloating-point values to be sorted:\n";
  std::vector<double> values{ -2.5, 1.4, -2.55, 6.3, 10.1, -40.5, 56.0, 4.7, 67.3, 45.0 };
  show(values, 10);
  sort(values);
  std::cout << "\nSorted floaating-point values:\n";
  show(values, 10);
}

template <typename T>
void swap(std::vector<T>& data, size_t first, size_t second)
{
  auto temp{data[first]};
  data[first] = data[second];
  data[second] = temp;
}

// Sort data in ascending sequence
template <typename T>
void sort(std::vector<T>& data)
{
  if (!data.empty())
    sort(data, 0, data.size() - 1);
}

template <typename T>
void sort(std::vector<T>& data, size_t start, size_t end)
{
  // start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;

  // Choose middle address to partition set
  swap(data, start, (start + end) / 2);    // Swap middle element with start element

  // Check data against chosen element
  size_t current {start};
  for (size_t i {start + 1}; i <= end; i++)
  {
    if (data[i] < data[start])     // Is element less than chosen element?
      swap(data, ++current, i);    // Yes, so swap to the left
  }

  swap(data, start, current);      // Swap chosen and last swapped elements

  if (current > start) sort(data, start, current - 1); // Sort left subset if exists
  if (end > current + 1) sort(data, current + 1, end); // Sort right subset if exists
}

template <typename T>
void show(const std::vector<T>& data, size_t width)
{
  const size_t data_per_line{ 80 / width - 1};
  std::cout << std::format("{:{}}", data[0], width); // Output first element

  size_t data_in_line {};         // Number of data in current line
  for (size_t i {1}; i < data.size(); ++i)
  {
    if (++data_in_line == data_per_line)
    {
      data_in_line = 0;
      std::cout << std::endl;
    }
    std::cout << std::format("{:{}}", data[i], width); // Output an element
  }
  std::cout << std::endl;
}