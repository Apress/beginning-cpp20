// Exercise 2-6. Format a table.

import <iostream>;
import <numbers>;
import <format>;

int main()
{
  // Define the format strings for the various rows of the table first
  const auto format_header     { "{:20} {:35} {}\n" };
  const auto format_precision5 { "{:20} {:35} {:.5f}...\n" };
  const auto format_precision3 { "{:20} {:35} {:.3f}...\n" };

  std::cout << std::format(format_header,     "Constant",            "Description",                       "Approximation");
  std::cout << std::format(format_precision5, "std::numbers::e",     "The base of the natural logarithm", std::numbers::e);
  std::cout << std::format(format_precision5, "std::numbers::pi",    "pi",                                std::numbers::pi);
  std::cout << std::format(format_precision5, "std::numbers::sqrt2", "Square root of 2",                  std::numbers::sqrt2);
  std::cout << std::format(format_precision3, "std::numbers::phi",   "The golden ration constant",        std::numbers::phi);
}