// Removing all elements that satisfy a certain condition using std::partition() / stable_partition().

/*
  Notes:
   - Normally one would use std::remove() (as this is slightly faster and more to the point),
     though std::partition() can be used for this as well.
   - You may notice that std::partition() reorders the elements that it keeps.
     It is implementation-defined whether this partition() preserves the original order or not.
     If you want to make sure the original order of the numbers is preserved,
     you need to use std::stable_partition()
*/
#include <vector>
#include <string_view>
#include <iostream>
#include <algorithm>

std::vector<int> fillVector_1toN(size_t N);  // Fill a vector with 1, 2, ..., N
void printVector(std::string_view message, const std::vector<int>& numbers);

void removeEvenNumbers(std::vector<int>& numbers)
{
  const auto first_even_number
    { std::stable_partition(begin(numbers), end(numbers), [](auto num) { return num % 2 == 1; }) };
  /*       ^^^^^^^^^^^^^^^^ if you use partition(), the order of the odd elements may become scrambled */ 
  
  numbers.erase(first_even_number, end(numbers));
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
  std::vector<int> numbers;
  for (int i{ 1 }; i <= N; ++i)
    numbers.push_back(i);
  return numbers;
}

void printVector(std::string_view message, const std::vector<int>& numbers)
{
  std::cout << message << ": ";
  for (int number : numbers) std::cout << number << ' ';
  std::cout << std::endl;
}