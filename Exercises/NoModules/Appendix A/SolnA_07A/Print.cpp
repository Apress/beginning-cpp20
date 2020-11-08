#include <iostream>
#include <string_view>

unsigned count;

void print(std::string_view string)
{
  std::cout << string << std::endl;
  ++count;
}
