// Exercise 8_6 Computing grade statistics
/*
  This is a bigger excercise, and thus many variations will be valid and correct.
  The focus here isn't on performance, it's on writing and calling functions.
  Main thing is that you:
    (1) got the parameter types right---mostly pass-by-reference-to-const 
        for the input parameters, except for sort() which modifies its argument.
    (2) made sure that the program does something correctly for empty grade lists,
        small grade lists (< 5 values), and for grade lists of both odd and even size.
  
  Some things worth noticing in our solution:
    - we overloaded the recursive sort() function by adding a helper function 
      that users can call without having to know what the second and third parameters are,
      and without having to think about the empty input case. 
      This is common with recursive algorithms: the interface that users use 
      will often not contain the actual recursive function.
    - we have used std::optional<> to deal with cases where, respectively, 
      there are less than 5 inputs, or no inputs at all.
      Without std::optional<> we'd have to encode the 'nullopt' somehow.
      Because we're dealing with unsigned values, 
      we could in this case still use negatives (-1, for instance).
      But what if we were instead computing the average of signed integers?
      Then -1 would be a perfectly valid average... 
      Doubles have special non-a-number (NaN) values, 
      but this would certainly be much less obvious to the caller than std::optional<>.
*/
#include <iostream>
#include <vector>
#include <cmath>    // for std::sqrt()
#include <optional>
#include <string>

void sort(std::vector<unsigned>& numbers);

void computeHighest(const std::vector<unsigned>& numbers, std::optional<unsigned>(&highest)[5]);
void computeLowest(const std::vector<unsigned>& numbers, std::optional<unsigned>(&lowest)[5]);

std::optional<double> computeAverage(const std::vector<unsigned>& numbers);
std::optional<double> computeMedian(const std::vector<unsigned>& numbers);
std::optional<double> computeStandardDeviation(const std::vector<unsigned>& numbers);
std::optional<double> computeVariance(const std::vector<unsigned>& numbers);

void printNumber(const std::string& label, const std::optional<double>& number);
void printNumbers(const std::string& label, const std::optional<unsigned>(&numbers)[5]);

int main()
{
  std::vector<unsigned> grades;

  std::cout << "Please enter a number of grades (0-100), terminated by a negative one:" << std::endl;
  while (true)
  {
    int number{};
    std::cin >> number;
    if (number < 0)
      break;
    else if (number > 100)
      std::cout << "Only numbers < 100, please..." << std::endl;
    else
      grades.push_back(number);
  }

  sort(grades);

  std::optional<unsigned> highest[5]{};
  std::optional<unsigned> lowest[5]{};

  computeHighest(grades, highest);
  computeLowest(grades, lowest);

  printNumbers("Five highest grades", highest);
  printNumbers("Five lowest grades", lowest);
  printNumber("The grade average", computeAverage(grades));
  printNumber("The median grade", computeMedian(grades));
  printNumber("The standard deviation of the grades", computeStandardDeviation(grades));
  printNumber("The variance of the grades", computeVariance(grades));
}

// Swap numbers at position first with address at position second
void swap(std::vector<unsigned>& numbers, size_t first, size_t second)
{
  auto temp{ numbers[first] };
  numbers[first] = numbers[second];
  numbers[second] = temp;
}

// Recursive helper function to sort numbers in ascending sequence
// Numbers to be sorted are from words[start] to words[end]
void sort(std::vector<unsigned>& numbers, size_t start, size_t end)
{
  // start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;

  // Choose middle address to partition set
  swap(numbers, start, (start + end) / 2);                            // Swap middle address with start

                                    // Check words against chosen word
  size_t current{ start };
  for (size_t i{ start + 1 }; i <= end; i++)
  {
    if (numbers[i] < numbers[start])                                 // Is word less than chosen word?
      swap(numbers, ++current, i);                                    // Yes, so swap to the left
  }

  swap(numbers, start, current);                                      // Swap the chosen word with last in

  if (current > start) sort(numbers, start, current - 1);             // Sort left subset if exists
  if (end > current + 1) sort(numbers, current + 1, end);             // Sort right subset if exists
}

// Sort numbers in ascending sequence
void sort(std::vector<unsigned>& numbers)
{
  if (!numbers.empty())
    sort(numbers, 0, numbers.size() - 1);
}

void computeHighest(const std::vector<unsigned>& numbers, std::optional<unsigned>(&highest)[5])
{
  const auto numHighest = static_cast<int>(std::size(highest));

  for (int i = 0; i < numHighest; ++i)
  {
    const int numberIndex =
      static_cast<int>(numbers.size()) - numHighest + i;
    if (numberIndex >= 0)
      highest[i] = numbers[numberIndex];
    else
      highest[i] = std::nullopt;
  }
}

void computeLowest(const std::vector<unsigned>& numbers, std::optional<unsigned>(&lowest)[5])
{
  for (size_t i = 0; i < std::size(lowest); ++i)
  {
    if (i < numbers.size())
      lowest[i] = numbers[i];
    else
      lowest[i] = std::nullopt;
  }
}

std::optional<double> computeAverage(const std::vector<unsigned>& numbers)
{
  if (numbers.empty())
    return std::nullopt;

  double average{};
  for (auto& number : numbers)
    average += number;
  return average / numbers.size();
}

std::optional<double> computeMedian(const std::vector<unsigned>& numbers)
{
  if (numbers.empty())
    return std::nullopt;

  const auto numNumbers = numbers.size();
  const auto middleIndex = numNumbers / 2;
  if (numNumbers % 2)
  {
    return numbers[middleIndex];
  }
  else
  {
    return static_cast<double>(numbers[middleIndex] + numbers[middleIndex - 1]) / 2;
  }
}

std::optional<double> computeStandardDeviation(const std::vector<unsigned>& numbers)
{
  if (numbers.empty())
    return std::nullopt;

  const double average = *computeAverage(numbers);
  double sum{};
  for (auto& number : numbers)
    sum += (number - average) * (number - average);
  return std::sqrt(sum / numbers.size());
}

std::optional<double> computeVariance(const std::vector<unsigned>& numbers)
{
  if (numbers.empty())
    return std::nullopt;

  const double standardDeviation = *computeStandardDeviation(numbers);
  return standardDeviation * standardDeviation;
}

void printNumber(const std::string& label, const std::optional<double>& number)
{
  std::cout << label << ": ";

  if (number)
    std::cout << *number;
  else
    std::cout << "n/a";

  std::cout << std::endl;
}

void printNumbers(const std::string& label, const std::optional<unsigned>(&numbers)[5])
{
  std::cout << label << ": ";

  for (auto& number : numbers)
  {
    if (number)
      std::cout << *number << ' ';
  }

  std::cout << std::endl;
}