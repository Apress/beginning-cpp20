// Exercise 20-12: exercising new range adaptors
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
  const unsigned max = 1'000;
  const unsigned per_line = 10;

  // As you no doubt deduced, drop_while() is not really applicable here,
  // but take_while() fits nicely!
  unsigned count{};
  for (auto prime : iota(2u) 
        | filter(&isPrime) 
        | take_while([max](unsigned prime) { return prime < max; }) 
        | reverse)
  {
    std::cout << prime << ' ';
    if (++count % per_line == 0)
      std::cout << std::endl;
  }
}
