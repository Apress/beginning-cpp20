// Obtaining the number of array elements
import <iostream>;
import <array>;       // for std::size()

int main()
{
  int values[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

  std::cout << "There are " << std::size(values) << " elements in the array.\n";

  int sum {};
  const size_t old_school_size{ sizeof(values) / sizeof(values[0]) };
  for (size_t i {}; i < old_school_size; ++i)
  {
    sum += values[i];
  }
  std::cout << "The sum of the array elements is " << sum << std::endl;
}
