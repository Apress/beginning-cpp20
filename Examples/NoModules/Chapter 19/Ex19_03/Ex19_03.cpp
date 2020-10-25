// Exercising the use of a functor as callback functions
#include <iostream>
#include "Optimum.h"
#include "Less.h"

template <typename T>
bool greater(const T& one, const T& other) { return one > other; }

int main()
{
  Less less;     // Create a 'less than' functor

  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::cout << "Minimum element: " << *findOptimum(numbers, less) << std::endl;
  std::cout << "Maximum element: " << *findOptimum(numbers, greater<int>) << std::endl;
}
