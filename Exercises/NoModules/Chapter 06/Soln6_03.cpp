// Exercise 6-3. Storing numbers in a dynamic array
// Btw: notice anything about the result? 
// Try increasing numbers of array elements...
#include <iostream>
#include <format>
#include <cmath>

int main()
{
  size_t n {};
  std::cout << "Enter the number of array elements: ";
  std::cin >> n;
  auto* values{ new double[n] };
  for (size_t i {}; i < n; ++i)
    *(values+i) = 1.0 / ((i + 1)*(i + 1));

  double sum {};
  for (size_t i {}; i < n; ++i)
    sum += values[i];

  std::cout << std::format("The result is {}", std::sqrt(6.0 * sum)) << std::endl;
  
  delete[] values;   // Don't forget to free the memory!
}