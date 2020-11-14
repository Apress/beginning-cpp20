#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string_view>

inline int count {};

inline void print(std::string_view string)
{
  std::cout << string << std::endl;
  ++count;
}

#endif