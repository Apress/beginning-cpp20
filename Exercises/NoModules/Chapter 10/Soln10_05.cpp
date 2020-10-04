// Exercise 10-5.cpp
// The easiest way to verify this is using a static variable.
// If indeed each function is only instantiated once, 
// then all calls should share the same static variable...
// You should see this being reflected in the program's output
// as main() starts by calling the function for doubles twice.
#include <iostream>
#include <format>
#include <string>

template<typename T> T larger(T a, T b);    // Function template prototype

int main()
{
  std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
  std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;

  int big_int {17011983}, small_int {10};
  std::cout << std::format("Larger of {} and {} is {}\n", 
                            big_int, small_int, larger(big_int, small_int));

  std::string a_string {"A"}, z_string {"Z"};
  std::cout << std::format(R"(Larger of "{}" and "{}" is "{}")", 
                           a_string, z_string, larger(a_string, z_string)) << std::endl;
}

// Template for functions to return the larger of two values
template <typename T>
T larger(T a, T b)
{
  static size_t counter{};
  std::cout << "This instantation has now been called " << ++counter << " time(s)\n";
  return a > b? a : b;
}
