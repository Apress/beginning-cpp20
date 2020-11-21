// Exercising two overloads of push_back(): one for lvalue arguments, and one for rvalue arguments
import array;
import <string>;
import <iostream>;

// Construct an Array<> of a given size, filled with some arbitrary string data
Array<std::string> buildStringArray(const size_t size)
{
  Array<std::string> result{ size };
  for (size_t i {}; i < size; ++i)
    result[i] = "You should learn from your competitor, but never copy. Copy and you die.";
  return result;
}

int main()
{
  Array<Array<std::string>> array_of_arrays;

  Array<std::string> array{ buildStringArray(1'000) };  
  array_of_arrays.push_back(array);              // Push an lvalue

  array.push_back("One more for good measure");
  std::cout << std::endl;

  array_of_arrays.push_back(std::move(array));   // Push an rvalue
}