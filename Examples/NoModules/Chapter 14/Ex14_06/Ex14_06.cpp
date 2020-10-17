// Destructors in a class hierarchy
#include <iostream>
#include "Carton.h"   // For the Carton class

int main()
{
  Carton carton;
  Carton candyCarton{50.0, 30.0, 20.0, "SBB"};	// Solid bleached board

  std::cout << "carton volume is " << carton.volume() << std::endl;
  std::cout << "candyCarton volume is " << candyCarton.volume() << std::endl;
}
