// Exercise 19-2. 
// Sorting in various ways using higher-order functions, functors, and lambda expressions.

#include <iostream>
#include <format>
#include <functional>
#include <cctype>         // For std::tolower()
#include <cmath>          // For std::abs()
#include "Sort.h"

// Output vector elements
template<typename T>
void list(const std::vector<T>& values, size_t width = 5)
{
  for (auto value : values)
    std::cout << std::format("{:{}}", value, width);
  std::cout << std::endl;
}

int main()
{
  std::vector numbers{ -2, 4, -5, 6, 10, -40, 56, 4, 67, 45 };
  std::cout << "\nIntegers to be sorted:\n";
  list(numbers);
  sort(numbers, std::greater<>{});
  std::cout << "\nSorted integers:\n";
  list(numbers);

  std::cout << "\nCharacters to be sorted:\n";
  std::vector letters{ 'C', 'd', 'a', 'z', 't', 'S', 'p', 'm', 'D', 'f' };
  list(letters, 2);
  sort(letters, [](char x, char y) { return std::tolower(x) < std::tolower(y); });
  std::cout << "\nSorted characters:\n";
  list(letters, 2);

  std::cout << "\nFloating-point values to be sorted:\n";
  std::vector values{ -2.5, 1.4, -2.55, 6.3, 10.1, -40.5, 56.0, 4.7, 67.3, 45.0 };
  list(values, 10);
  sort(values, [](double x, double y) { return std::abs(x) < std::abs(y); });
  std::cout << "\nSorted floaating-point values:\n";
  list(values, 10);
}