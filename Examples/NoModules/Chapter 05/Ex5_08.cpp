// Using the continue statement to display ASCII character codes
#include <iostream>
#include <format>
#include <cctype>

int main()
{
  const auto header_format{ "{:^11}{:^11}{:^11}\n" };    // 3 cols., 11 wide, centered (^)
  const auto body_format{ "{0:^11}{0:^11X}{0:^11d}\n" }; // Print same argument three times

  std::cout << std::format(header_format, "Character", "Hexadecimal", "Decimal");

  // Output 7-bit ASCII characters and corresponding codes
  char ch{};
  do
  {
    if (!std::isprint(ch))  // If it's not printable...
      continue;             // ...skip this iteration
    std::cout << std::format(body_format, ch);
  } while (ch++ < 127);
}
