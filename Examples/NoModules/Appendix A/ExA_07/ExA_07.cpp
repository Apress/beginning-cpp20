// Calling external functions
#include <iostream>
#include <format>

double power(double x, int n);   // Declaration of an external power() function

int main()
{
  for (int i{ -3 }; i <= 3; ++i)  // Calculate powers of 8 from -3 to +3
    std::cout << std::format("{:10}\n", power(8.0, i));
  std::cout << std::endl;
}
