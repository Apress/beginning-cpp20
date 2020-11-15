// Removing all elements that satisfy a certain condition usign std::erase_if()
import <vector>;
import <string_view>;
import <iostream>;

std::vector<int> fillVector_1toN(size_t N);  // Fill a vector with 1, 2, ..., N
void printVector(std::string_view message, const std::vector<int>& numbers);

void removeEvenNumbers(std::vector<int>& numbers)
{
  std::erase_if(numbers, [](int number) { return number % 2 == 0; });
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
