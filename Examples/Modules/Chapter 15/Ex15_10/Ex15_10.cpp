// Using an abstract class
#include <iostream>
#include "Box.h"                                 // For the Box class
#include "ToughPack.h"                           // For the ToughPack class
#include "Carton.h"                              // For the Carton class

int main()
{
  // Box box{20.0, 30.0, 40.0};                  // Uncomment for compiler error

  ToughPack hardcase {20.0, 30.0, 40.0};         // A derived box - same size
  Carton carton {20.0, 30.0, 40.0, "plastic"};   // A different derived box

  Box*pBox {&hardcase};                          // Base pointer - derived address
  std::cout << "hardcase volume is " << pBox->volume() << std::endl;

  pBox = &carton;                                // New derived address
  std::cout << "carton volume is " << pBox->volume() << std::endl;
}
