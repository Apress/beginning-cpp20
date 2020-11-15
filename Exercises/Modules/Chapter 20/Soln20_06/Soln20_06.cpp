// Removing all elements that satisfy a certain condition 
// while iterating over a container
#include <vector>
#include <string_view>
#include <iostream>
#include <algorithm>   // for std::remove_if()
#include <numeric>     // for std::iota()

/*
  Note: std::ranges::iota() does not exist. No doubt because 
  the <ranges> module defines a std::ranges::views::iota range factory.
  Maybe you can alter this solution to use that view instead to fill the vector?
  (Note: in the next exercise you are asked to not use a vector at all,
   but operate directly with views...)
*/

std::vector<int> fillVector_1toN(size_t N);       // Fill a vector with 1, 2, ..., N
void printVector(std::string_view message, const std::vector<int>& numbers);

template <typename Auto>
void removeEvenNumbers(Auto& numbers)    /* Using more elegant std::erase_if() */
{
  std::erase_if(numbers, [](auto number) { return number % 2 == 0; });
}

int main()
{
  const size_t num_numbers{ 20 };

  auto numbers{ fillVector_1toN(num_numbers) };

  printVector("The original set of numbers", numbers);

  removeEvenNumbers(numbers);

  printVector("The numbers that were kept", numbers);
}

std::vector<int> fillVector_1toN(size_t N)
{
  std::vector<int> numbers(N);
  std::iota(begin(numbers), end(numbers), 1);
  return numbers;
}

void printVector(std::string_view message, const std::vector<int>& numbers)
{
  std::cout << message << ": ";
  for (int number : numbers) std::cout << number << ' ';
  std::cout << std::endl;
}
