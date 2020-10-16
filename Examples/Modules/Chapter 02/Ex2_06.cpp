// Formatting numeric values with std::format() 
#include <iostream>
#include <format>
#include <numbers>

int main()
{
  const double pi{ std::numbers::pi };
  std::cout << std::format("Default: {:.2}, fixed: {:.2f}, scientific: {:.2e}, "
    "general: {:.2g}\n", pi, pi, pi, pi);
  std::cout << std::format("Default: {}, binary: {:b}, hex.: {:x}\n", 314, 314, 314);
  std::cout << std::format("Default: {}, decimal: {:d}, hex.: {:x}\n", 'c', 'c', 'c');
  std::cout << std::format("Alternative hex.: {:#x}, binary: {:#b}, HEX.: {:#X}\n",
    314, 314, 314);
  std::cout << std::format("Forced sign: {:+}, space sign: {: }\n", 314, 314);
  std::cout << std::format("All together: {:*<+10.4f}, {:+#09x}\n", pi, 314);
}
