// Defining classes with in-class member definitions.

#include <iostream>   // For use of std::cout, std::endl, etc.
#include "Box.h"      // For use of the Box class

int main()
{
  Box myBox{ 6.0, 6.0, 18.5 }; // Create a box
  std::cout << "Volume of the first Box object is " << myBox.volume() << std::endl;
}