// Overloading on const
#include "Box.h"
#include <iostream>

int main()
{
  const Box constBox{ 1, 2, 3 };
  // constBox.length() = 2;                          // Does not compile: good!
  std::cout << constBox.length() << std::endl;

  Box nonConstBox{ 3, 2, 1 };
  nonConstBox.length() *= 2;
  std::cout << nonConstBox.length() << std::endl;
}
