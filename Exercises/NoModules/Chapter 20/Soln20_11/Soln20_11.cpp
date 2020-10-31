// Exercise 20-11: exercising range factories and range adaptors
#include <iostream>
#include <algorithm>
#include <ranges>
#include <cmath>

using namespace std::ranges::views;

bool isPrime(unsigned number)   
{
  // Of course we use an algorithm and a range factory here as well!
  return std::ranges::none_of(
    iota(2, static_cast<int>(std::sqrt(number))),
    [number](int divisor) { return number % divisor == 0; }
  );
}

int main()
{
  const unsigned num_primes = 100;
  const unsigned per_line = 10;

  unsigned count{};
  for (auto prime : iota(2) | filter(&isPrime) | take(num_primes) | reverse)
  {
    std::cout << prime << ' ';
    if (++count % per_line == 0)
      std::cout << std::endl;
  }
}
