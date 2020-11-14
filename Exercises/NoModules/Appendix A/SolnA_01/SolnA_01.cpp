// Exercise A-1   Defining a function-like macro
#include <iostream>
#include <format>

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