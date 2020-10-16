// Exercise 5-1 Squaring odd numbers
#include <iostream>
#include <format>

int main()
{
  int limit {};
  std::cout << "Enter the upper limit for squared odd numbers: ";
  std::cin >> limit;
  for (int i {1}; i <= limit; i += 2)
  {
    std::cout << std::format("{:4} squared is {:8}\n", i, i * i);
  }
}