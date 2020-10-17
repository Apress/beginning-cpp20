// Apllying a using declaration to restore public access for inhertied member
#include <iostream>
#include "Box.h"
#include "Carton.h"

int main()
{
  // Create a Box object and two Carton objects
  Box box {40.0, 30.0, 20.0};
  Carton carton;
  Carton candyCarton {"Thin cardboard"};

  // Check them out - sizes first of all
  std::cout << "box occupies " << sizeof box << " bytes" << std::endl;
  std::cout << "carton occupies " << sizeof carton << " bytes" << std::endl;
  std::cout << "candyCarton occupies " << sizeof candyCarton << " bytes" << std::endl;

  // Now volumes...
  std::cout << "box volume is " << box.volume() << std::endl;
  std::cout << "carton volume is " << carton.volume() << std::endl;
  std::cout << "candyCarton volume is " << candyCarton.volume() << std::endl;

  // Uncomment any of the following for an error...
  //  std::cout << "candyCarton length is " << candyCarton.getLength() << std::endl; 
  // box.length = 10.0;
  // candyCarton.length = 10.0;
}
