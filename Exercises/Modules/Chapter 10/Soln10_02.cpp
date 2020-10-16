// Exercise 10-2.cpp
// Using auto instead of std::string resulted in a type change for a_string and z_string:
// they now both have the type const char[], the type given to string literals.
// If you instantiate the original template for this type, it therefore becomes
//   
//   const char* larger(const char* a, const char* b)
//   {
//     return a > b? a : b;
//   }
//
// This function now compares the pointers of both string literals rather than the 
// string literals themselves. To solve this, you should create a specialisation 
// for const char* arrays. 

#include <iostream>
#include <string_view>

template<typename T>                     // Function template prototype
T larger(T a, T b);                      

template<>                               // Function template specialization prototype
const char* larger(const char* a, const char* b);  

int main() 
{
  std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
  std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;

  const int big_int {17011983}, small_int {10};
  std::cout << "Larger of " << big_int << " and " << small_int << " is "
            << larger(big_int, small_int) << std::endl;

  const auto a_string {"A"}, z_string {"Z"};		// now string literals (type const char[])!
  std::cout << "Larger of \"" << a_string << "\" and \"" << z_string << "\" is "
            << '"' << larger(a_string, z_string) << '"' << std::endl;
}

// Template for functions to return the larger of two values
template <typename T>
T larger(T a, T b)
{
  return a > b? a : b;
}

// Template specialization for returning the larger of two character arrays 
// (such as string literals).
//
// Note: instead of std::string_view, you could've used std::string as well,
// but that would've involved copying the character arrays. 
// std::string_view is therefore the preferred C++ type to use here.
template<>
const char* larger(const char* a, const char* b)
{
  return std::string_view{a} > std::string_view{b}? a : b;
}

/*
// Template specialization for returning the larger of two character arrays 
// (such as string literals).
// Alternative implementation using the C-style function strcmp() 
// (you'll need to include the <cstring> header to make this compile).
// The strcmp() function returns a value larger than zero if a > b; 
// zero if both arguments are equal, a negative value if a < b.
template<>
const char* larger(const char* a, const char* b)
{
  return std::strcmp(a, b) > 0;
}
*/