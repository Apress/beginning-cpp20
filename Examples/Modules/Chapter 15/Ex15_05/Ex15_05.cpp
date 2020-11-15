// Using a reference parameter to call virtual function
#include <iostream>
#include "Box.h"            // For the Box class
#include "ToughPack.h"      // For the ToughPack class
#include "Carton.h"         // For the Carton class

// Global function to display the volume of a box
void showVolume(const Box& box)
{
  std::cout << "Box usable volume is " << box.volume() << std::endl;
}

int main()
{
  Box box {20.0, 30.0, 40.0};                  // A base box
  ToughPack hardcase {20.0, 30.0, 40.0};       // A derived box - same size
  Carton carton {20.0, 30.0, 40.0, "Plastic"}; // A different derived box

  showVolume(box);       // Display volume of base box
  showVolume(hardcase);  // Display volume of derived box
  showVolume(carton);    // Display volume of derived box
}
