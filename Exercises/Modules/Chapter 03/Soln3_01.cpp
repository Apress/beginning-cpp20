// Exercise 3-1. Output an integer and its complements in binary and decimal.

// This tests how well you remember string formatting using std::format()
// (see Chapter 2 if you forgot some of the formatting options), 
// as well as two's complement binary encoding and bitwise ~.

import <iostream>;
import <format>;

// See Appendix A (available online) for static_assert().
// You should adjust the field widths of the table if ints have a different size.
static_assert(sizeof(int) == 4, "This program assumes 32 bit ints");

int main()
{
  int value {};
  std::cout << "Enter any integer: ";
  std::cin >> value;
  
  const auto inverted{ static_cast<unsigned>(~value) };

  // Output column headings (0b and 32 bits make for a width of 34)
  std::cout << std::format(" {:^34} {:^34} {:^34}\n", "value", "~value", "~value + 1");

  // Output binary values (cast to unsigned integers first for more realistic output)
  std::cout << std::format(" {:#034b} {:#034b} {:#034b}\n", value, inverted, inverted + 1);

  // Output decimal values
  std::cout << std::format(" {:^34} {:^34} {:^34}\n", value, ~value, ~value + 1);
}