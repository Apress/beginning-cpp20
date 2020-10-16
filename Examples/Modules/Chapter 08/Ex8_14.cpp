// Overloading a function
import <iostream>;
import <string>;
import <vector>;

// Function prototypes
double largest(const double data[], size_t count);
double largest(const std::vector<double>& data);
int largest(const std::vector<int>& data);
std::string largest(const std::vector<std::string>& words);
// int largest(const std::vector<std::string>& words); 
            /* Above function overload would not compile: overloaded functions
               must differ in more than just their return type! */
int main()
{
  double array[] {1.5, 44.6, 13.7, 21.2, 6.7};
  std::vector<int> numbers {15, 44, 13, 21, 6, 8, 5, 2};
  std::vector<double> data{3.5, 5, 6, -1.2, 8.7, 6.4};
  std::vector<std::string> names {"Charles Dickens", "Emily Bronte", 
                                  "Jane Austen", "Henry James", "Arthur Miller"};
  std::cout << "The largest of array is " << largest(array, std::size(array)) 
                        << std::endl;
  std::cout << "The largest of numbers is " << largest(numbers) << std::endl;
  std::cout << "The largest of data is " << largest(data) << std::endl;
  std::cout << "The largest of names is " << largest(names) << std::endl;
}

// Finds the largest of an array of double values
double largest(const double data[], size_t count)
{
  double max{ data[0] };
  for (size_t i{ 1 }; i < count; ++i)
    if (max < data[i]) max = data[i];
  return max;
}

// Finds the largest of a vector of double values
double largest(const std::vector<double>& data)
{
  double max {data[0]};
  for (auto value : data)
    if (max < value) max = value;
  return max;
}

// Finds the largest of a vector of int values
int largest(const std::vector<int>& data)
{
  int max {data[0]};
  for (auto value : data)
    if (max < value) max = value;
  return max;
}

// Finds the largest of a vector of string objects
std::string largest(const std::vector<std::string>& words)
{
  std::string max_word {words[0]};
  for (const auto& word : words)
    if (max_word < word) max_word = word;
  return max_word;
}
