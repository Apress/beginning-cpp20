// Exercise 13-2
// Implementing the * operator for the Box class to pre-multiply by a number
#include <iostream>
#include "Box.h"

int main()
{
  Box box {2, 3, 4};
  std::cout << "Box is " << box << std::endl;
  unsigned n {3};
  Box newBox{ n * box };
  std::cout << "After pre-multiplying by " << n << " box is " << newBox << std::endl;
}
