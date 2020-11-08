// Exercise A-1   Defining a function-like macro
#include <iostream>
#include <format>
#include <cstdlib> 

/* 
  Only complication is the need for () around condition to avoid
  expanding to expressions such as !x < y. Best do the same for message
  as well to avoid similar operator precedence issues there.
  This confirms, yet again, that using function-like macros often leads
  to needlessly fragile code.
 */

#define ASSERT(condition, message)       \
  if (!(condition))                      \
  {                                      \
    std::cerr << (message) << std::endl; \
    std::abort();                        \
  }                                      \

int main()
{
  int y{ 5 };

  for (int x{}; x < 20; ++x)
  {
    std::cout << std::format("x = {}\ty = {}", x, y) << std::endl;
    ASSERT(x < y, "Whoopsidaisies, too far!");
  }
}