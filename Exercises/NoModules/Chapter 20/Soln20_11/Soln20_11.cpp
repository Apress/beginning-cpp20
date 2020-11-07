// Exercise 20-11: exercising range factories and range adaptors
#include <iostream>
#include <algorithm>
#include <ranges>
#include <cmath>

using namespace std::ranges::views;

bool isPrime(unsigned number)   
{
  // Of course we use an algorithm and a range factory here as well!
  // Caution: mind the corner cases where number is 0, 1, or 2!
  return number >= 2 
    && std::ranges::none_of(
          iota(2u, static_cast<unsigned>(std::sqrt(number) + 1)),
          [number](unsigned divisor) { return number % divisor == 0; }
       );
}

int main()
{
  const unsigned num_primes{ 100 };
  const unsigned per_line{ 10 };

  unsigned count{};
  for (auto prime : iota(2) | filter(&isPrime) | take(num_primes) | reverse)
  {
    std::cout << prime << ' ';
    if (++count % per_line == 0)
      std::cout << std::endl;
  }
}
