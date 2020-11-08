// Calling external functions that are declared in a header file
#include <iostream>
#include <format>

#include "Power.h"

int main()
{
  for (int i{ -3 }; i <= 3; ++i)  // Calculate powers of 8 from -3 to +3
    std::cout << std::format("{:10}\n", power(8.0, i));
  std::cout << std::endl;
}
