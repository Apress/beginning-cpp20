// Exercise 3-6. Swapping integers.

import <iostream>;
import <print>;

int main()
{
  int first {}, second {};
  std::print("Enter two integers separated by a space: ");
  std::cin >> first >> second;

  first ^= second;
  second ^= first;
  first ^= second;
  std::println("In reverse order they are {} and {}", first, second);
}