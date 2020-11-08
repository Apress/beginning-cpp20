// Using a local helper function with internal linkage (see Power.cpp)
#include <iostream>
#include <format>

extern double power(double x, int n);  // Declaration of an external power() function

int main()
{
  for (int i{ -3 }; i <= 3; ++i)  // Calculate powers of 8
    std::cout << std::format("{:10}\n", power(8.0, i));
  std::cout << std::endl;
}
