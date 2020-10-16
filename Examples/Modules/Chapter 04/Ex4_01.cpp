// Comparing data values
#include <iostream>

int main()
{
  char first {};      // Stores the first character
  char second {};     // Stores the second character

  std::cout << "Enter a character: ";
  std::cin >> first;

  std::cout << "Enter a second character: ";
  std::cin >> second;

  // std::cout << std::boolalpha;   /* Output true/false instead of 1/0 */

  std::cout << "The value of the expression " << first << '<' << second
            << " is " << (first < second) << std::endl;
  std::cout << "The value of the expression " << first << "==" << second
            << " is " << (first == second) << std::endl;
}
