// Attempting to call a function with internal linkage from a different translation unit
#include <iostream>
#include <format>

double localHelper(double x, unsigned n); // Declares an external localHelper() function

int main()
{
  for (unsigned i{ 0 }; i <= 5; ++i)  // Calculate positive powers of 8
    std::cout << std::format("{:10}\n", localHelper(8.0, i));
  std::cout << std::endl;
}
