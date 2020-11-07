// Removing all elements that satisfy a certain condition 
// while iterating over a container
#include <vector>
#include <string_view>
#include <iostream>
#include <ranges>

using namespace std::ranges::views;

template <typename Auto>
void printVector(std::string_view message, Auto& numbers)
{
  std::cout << message << ": ";
  for (int number : numbers) std::cout << number << ' ';
  std::cout << std::endl;
}

int main()
{
  const size_t num_numbers{ 20 };

  auto numbers{ iota(1, 20) };

  printVector("The original set of numbers", numbers);

  auto odd_numbers{ numbers | filter([](int i) { return i % 2 != 0; }) };

  printVector("The numbers that were kept", odd_numbers);
}

