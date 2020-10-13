// Exercise 6-6. Storing a dynamically allocated vector in a smart pointer

#include <iostream>
#include <format>
#include <cmath>
#include <vector>
#include <memory>

int main()
{
  size_t n {};
  std::cout << "Enter the number of vector elements: ";
  std::cin >> n;
  auto values{ std::make_unique<std::vector<double>>(n) };

  for (size_t i {}; i < n; ++i)
    (*values)[i] = 1.0 / ((i + 1)*(i + 1));
  
  double sum {};
  for (auto value : *values)
    sum += value;

  std::cout << std::format("Result is {}", std::sqrt(6.0*sum)) << std::endl;
  
  // No need to deallocate the memory yourself anymore: the smart pointer takes care of that for you!
}