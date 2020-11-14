// Exercise A-2   Conditional compilation
#include <iostream>
#include <format>

// Define (before including ASSERT.h) to disable the assertion
#define NDEBUG
#include "ASSERT.h"

int main()
{
  int y{ 5 };

  for (int x{}; x < 20; ++x)
  {
    std::cout << std::format("x = {}\ty = {}", x, y) << std::endl;
    ASSERT(x < y, "Whoopsidaisies, too far!");
  }
}