// Exercise 6-5. Managing a dynamic array using a smart pointer
// You can no longer use pointer notation now!
// (You could, technically, call get() first and then use pointer notation,
// though why make the syntax even more convoluted: just use array notation!)

import <iostream>;
import <format>;
import <memory>;

#include <cmath>

int main()
{
  size_t n {};
  std::cout << "Enter the number of array elements: ";
  std::cin >> n;
  auto values{ std::make_unique<double[]>(n) };
  for (size_t i {}; i < n; ++i)
    values[i] = 1.0 / ((i + 1)*(i + 1));

  double sum {};
  for (size_t i {}; i < n; ++i)
    sum += values[i];

  std::cout << std::format("The result is {}", std::sqrt(6.0 * sum)) << std::endl;
  
  // No need to deallocate the memory yourself anymore: the smart pointer takes care of that for you!
}