// Overloading a unary "rotate" operator
#include <iostream>
#include "Box.h"

int main()
{
  Box someBox{ 1, 2, 3 };
  std::cout << ~someBox << std::endl;
}
