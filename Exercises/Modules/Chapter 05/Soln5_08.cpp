// Exercise 5-08. Generate 93 Fibonacci numbers stored in an array.
// Of course 93 was not an arbitrary choice for the number of Fibonacci numbers.
// Fibonacci number grow fairly rapidly.
// 93 is the most that are possible with type unsigned long long on most platforms.

import <iostream>;
import <array>;

// See Appendix A (available online) for static_assert()
static_assert(sizeof(unsigned long long) >= 8,
  "This program assumes the depth of unsigned long long is (at least) 64 bit.");

int main()
{
  const size_t n {93};
  std::array<unsigned long long, n> fib;
  fib[0] = fib[1] = 1UL;
  for (size_t i {2}; i < n; ++i)
    fib[i] = fib[i - 1] + fib[i - 2];

  std::cout << "The first " << n << " Fibonacci numbers are:\n";
  for (auto number : fib)
  {
    std::cout << number << std::endl;
  }
}
