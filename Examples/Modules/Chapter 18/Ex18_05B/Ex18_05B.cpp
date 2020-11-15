// Exercising a single overload of push_back() 
// that can be used to either to add a copy of, or move, a new value into an Array<>.
// The caller decides whether the element is copied or moved.
#include "Array.h"
#include <string>

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