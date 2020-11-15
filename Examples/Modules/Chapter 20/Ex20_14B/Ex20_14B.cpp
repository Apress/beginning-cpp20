// Removing all elements that satisfy a certain condition 
// usign the remove-erase idiom and the range-based version of std::remove_if.
// Unlike the iterator-based version, std::ranges::erase_if() returns a subrange, 
// and not an iterator. 
// Note also that in this case std::erase_if() is even more compact (see Ex20_14A).
#include <vector>
#include <string_view>
#include <iostream>
#include <algorithm>

std::vector<int> fillVector_1toN(size_t N);  // Fill a vector with 1, 2, ..., N
void printVector(std::string_view message, const std::vector<int>& numbers);

void removeEvenNumbers(std::vector<int>& numbers)
{
  // Use the remove_if() algorithm to remove all even numbers
  auto [first_to_erase, last_to_erase] 
    { std::ranges::remove_if(numbers, [](int number) { return number % 2 == 0; }) };
  // Erase all elements including and beyond first_to_erase  
  numbers.erase(first_to_erase, last_to_erase);
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
