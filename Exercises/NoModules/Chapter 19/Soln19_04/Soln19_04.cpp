// Exercise 19-4. 
// Collecting values using higher-order functions, functors, and lambda expressions.

/*
	There are several ways to check for palindromes. 
	One of the more elegant solutions probably though is the recursive one shown here.
	While recursive lambdas are possible, more or less, recursion is far easier with a regular function.

	Note that to collect upper case letters, there's no need for a lambda either.
	Just use a pointer to the std::isupper() function as the callback!
*/

#include <iostream>
#include <format>
#include <functional>
#include <cctype>         // For std::isupper()
#include <string>
#include "Collect.h"

// Output vector elements
template<typename T>
void list(const std::vector<T>& values, size_t width = 5)
{
  for (auto value : values)
    std::cout << std::format("{:{}}", value, width);
  std::cout << std::endl;
}

bool is_palindrome(std::string_view s)
{
  return s.length() == 0
    || (s.front() == s.back() && is_palindrome(s.substr(1, s.length() - 2)));
}

int main()
{
  const std::vector numbers{ -2, 4, -5, 6, 10, -40, 56, 4, 67, 45 };
  std::cout << "\nAll numbers:\n";
  list(numbers);
  
  int threshold {};
  std::cout << "\nPlease enter a threshold: ";
  std::cin >> threshold;
  
  const auto greater{ collect(numbers, [threshold](int i) { return i > threshold; }) };
  std::cout << "Numbers greater than " << threshold << ":\n";
  list(greater);

  const std::vector letters{ 'C', 'd', 'a', 'z', 't', 'S', 'p', 'm', 'D', 'f' };
  std::cout << "\nAll characters:\n";
  list(letters, 2);
  //const auto capitals{ collect(letters, std::isupper) };	// <-- This should but does not work with all compilers
  const auto capitals{ collect(letters, isupper) };
  std::cout << "\nCapital letters:\n";
  list(capitals, 2);

  const std::vector<std::string> strings{ "palindrome", "racecar", "rubarb", "noon", "kayak", "ananas", "madam", "backwards" };
  std::cout << "\nAll strings:\n";
  list(strings, 12);
  const auto palindromes{ collect(strings, is_palindrome) };
  std::cout << "\nPalindromes:\n";
  list(palindromes, 10);
}