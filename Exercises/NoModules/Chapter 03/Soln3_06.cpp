// Exercise 3-5. Swapping integers.

#include <iostream>

int main()
{
  int first {}, second {};
  std::cout << "Enter two integers separated by a space: ";
  std::cin >> first >> second;

  first ^= second;
  second ^= first;
  first ^= second;
  std::cout << "In reverse order they are " << first << " and " << second << std::endl;
}