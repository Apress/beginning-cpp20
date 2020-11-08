// Using an externally defined constant
#include <iostream>
#include <format>

extern double power(double x, int n);  // Declaration of an external power() function
extern const int power_range;          // Declaration of an external global constant

int main()
{
  for (int i{ -power_range }; i <= power_range; ++i)  // Calculate powers of 8
    std::cout << std::format("{:10}\n", power(8.0, i));
  std::cout << std::endl;
}
