// Inserting in and erasing from sequence containers
import <iostream>;
import <vector>;

void printVector(const std::vector<int>& v);

int main()
{
  std::vector numbers{ 2, 4, 5 };     // Deduced type: std::vector<int>
  numbers.insert(numbers.begin(), 1); // Add single element to the beginning of the sequence
  printVector(numbers);   // 1 2 4 5

  numbers.insert(numbers.begin() + numbers.size() / 2, 3); // Add in the middle
  printVector(numbers);   // 1 2 3 4 5

  std::vector more_numbers{ 6, 7, 8 };
  numbers.insert(numbers.end(), more_numbers.begin(), more_numbers.end());
  printVector(numbers);   // 1 2 3 4 5 6 7 8

  numbers.erase(numbers.end() - 3, numbers.end());      // Erase last 3 elements
  numbers.erase(numbers.begin() + numbers.size() / 2);  // Erase the middle element
  numbers.erase(numbers.begin());                       // Erase the first element
  printVector(numbers);   // 2 4 5
}

void printVector(const std::vector<int>& v)
{
  for (auto i : v) std::cout << i << ' ';
  std::cout << std::endl;
}