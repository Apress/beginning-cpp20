// Exercise 20-12: exercising new range adaptors
import <iostream>;
import <algorithm>;
import <ranges>;
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
  const unsigned max{ 1'000 };
  const unsigned per_line{ 10 };

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
