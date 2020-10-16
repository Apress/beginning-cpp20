// Exercise 10-3.cpp
// Defining a function template for adding numbers, 
// and an overload that works for pointer types.
// Extra: also make plus() work with string literals...
import <iostream>;
import <string>;
import <string_view>;

template <typename T>
T plus(const T& a, const T& b)
{
    return a + b;
}

// Overload with another template for pointer types
template <typename T>
T plus(const T* a, const T* b)
{
    return *a + *b;
}

// Result cannot be const char*, but has to be a new object.
// Function template specialization can thus not be used either
// (but that is, as you know, never a good idea anyway!).
std::string plus(const char* a, const char* b)
{
  return std::string{ a } + b;
}

int main()
{
    int n{ plus(3, 4) };
    std::cout << "plus(3, 4) returns " << n << std::endl;
    
    double d{ plus(3.2, 4.2) };
    std::cout << "plus(3.2, 4.2) returns " << d << std::endl;
    
    std::string s1{ "aaa" };
    std::string s2{ "bbb" };
    auto s3{ plus(s1, s2) };
    std::cout << "With s1 as " << s1 << " and s2 as " << s2 << std::endl;
    std::cout << "plus(s1, s2) returns " << s3 << std::endl;

    // The extra part:
    std::string s{ plus("he", "llo") };
    std::cout << "plus(\"he\", \"llo\") returns " << s << std::endl;
}