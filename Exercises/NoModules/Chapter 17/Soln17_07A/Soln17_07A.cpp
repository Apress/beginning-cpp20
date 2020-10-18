// Implementing a custom std::formatter<> specialization to format Box objects
// (Alternate solution)
#include "Box.h"
#include "BoxFormatter.h"
#include <iostream>

int main()
{
  Box box{ 1, 2, 3 };
  std::cout << std::format("My new box, {:.2}, is fabulous!", box);
}