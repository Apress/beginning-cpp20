// Exercise 9-4. Using std::optional<>
import <iostream>;
import <string>;
import <vector>;
import <array>;
import <span>;
import <optional>;

// Function prototypes
std::optional<double> largest(std::span<const double> data);
std::optional<int> largest(std::span<const int> data);
std::optional<std::string> largest(std::span<const std::string> words);

int main()
{
  const double array[]{ 1.5, 44.6, 13.7, 21.2, 6.7 };
  const std::vector numbers{ 15, 44, 13, 21, 6, 8, 5, 2 };
  const std::vector data{ 3.5, 5.0, 6.0, -1.2, 8.7, 6.4 };
  const std::array array_data{ 3.5, 5.0, 6.0, -1.2, 8.7, 6.4 }; // Throwing in an std::array for good measure
  const std::vector<std::string> names{ "Charles Dickens", "Emily Bronte",
                                  "Jane Austen", "Henry James", "Arthur Miller" };
  std::cout << "The largest of array is " << *largest(array) << std::endl;            // Crashes if nullopt is returned
  std::cout << "The largest of numbers is " << largest(numbers).value() << std::endl; // Throws exception (see Chapter 16) for nullopt
  std::cout << "The largest of data is " << largest(data).value() << std::endl;
  std::cout << "The largest of array_data is (also) " << *largest(array_data) << std::endl;
  std::cout << "The largest of names is " << largest(names).value_or("<null>") << std::endl;
}

// Finds the largest of a span of values
std::optional<double> largest(std::span<const double> data)
{
  if (data.empty()) return {};  // Or return std::nullopt;

  double max{ data[0] };
  for (auto value : data)
    if (max < value) max = value;
  return max;
}

// Finds the largest of a vector of int values
std::optional<int> largest(std::span<const int> data)
{
  if (data.empty()) return {};  // Or return std::nullopt;

  int max{ data[0] };
  for (auto value : data)
    if (max < value) max = value;
  return max;
}

// Finds the largest of a vector of string objects
std::optional<std::string> largest(std::span<const std::string> words)
{
  if (words.empty()) return {};  // Or return std::nullopt;

  std::string max_word{ words[0] };
  for (const auto& word : words)
    if (max_word < word) max_word = word;
  return max_word;
}
