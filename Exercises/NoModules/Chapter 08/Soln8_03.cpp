// Exercise 8_3 Checking the number of arguments entered at the command line. 
#include <iostream>

int main(int numArguments, char* arguments[])
{
  switch (numArguments - 1)
  {
  case 2: case 3: case 4:
    for (size_t i {1}; i < numArguments; ++i)
      std::cout << "Argument " << i << " is " << arguments[i] << std::endl;
    break;
  default:
    std::cout << "You entered the incorrect number of arguments.\n"
              << "Please enter 2, 3 or 4 arguments. " << std::endl;
  }
}