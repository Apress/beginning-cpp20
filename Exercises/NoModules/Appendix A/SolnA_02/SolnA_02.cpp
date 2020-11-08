// Exercise A-2   Conditional compilation
#include <iostream>
#include <format>
#include <cstdlib> 

// Define to disable the assertion in main()
#define NDEBUG

#ifndef NDEBUG
  #define ASSERT(condition, message)       \
    if (!(condition))                      \
    {                                      \
      std::cerr << (message) << std::endl; \
      std::abort();                        \
    }
#else
  #define ASSERT(condition, message)
#endif

int main()
{
  int y{ 5 };

  for (int x{}; x < 20; ++x)
  {
    std::cout << std::format("x = {}\ty = {}", x, y) << std::endl;
    ASSERT(x < y, "Whoopsidaisies, too far!");
  }
}