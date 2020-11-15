// Range factories and range adaptors
#include <iostream>
#include <ranges>   // For views, range factories, and range adaptors

using namespace std::ranges::views;

bool isEven(int i) { return i % 2 == 0; }
int squared(int i) { return i * i; }

int main()
{
  for (int i : iota(1, 10))       // Lazily generate range [1,10)
    std::cout << i << ' ';
  std::cout << std::endl;

  for (int i : iota(1, 1000) | filter(isEven) | transform(squared)
    | drop(2) | take(5) | reverse)
    std::cout << i << ' ';
  std::cout << std::endl;
}
