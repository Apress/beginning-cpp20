// Using the named comparison functions
#include <compare>  // Required when using operator <=> (even for fundamental types)
#include <format>
#include <iostream>

int main()
{
  std::cout << "Please enter a number: ";

  int value;
  std::cin >> value;

  std::strong_ordering ordering{ value <=> 0 };

  std::cout << std::format("value < 0: {}\n", std::is_lt(ordering));  // is less than
  std::cout << std::format("value > 0: {}\n", std::is_gt(ordering));  // is greater than
  std::cout << std::format("value == 0: {}\n", std::is_eq(ordering)); // is equivalent
}
