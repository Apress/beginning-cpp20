// Behavior of inherited functions in a derived class
#include "Box.h"                                // For the Box class
#include "ToughPack.h"                          // For the ToughPack class

int main()
{
  Box box {20.0, 30.0, 40.0};            // Create a box
  ToughPack hardcase {20.0, 30.0, 40.0}; // Create a tough pack - same size

  box.showVolume();      // Display volume of base box (calls volume() for box)
  hardcase.showVolume(); // Display volume of derived box (call volume() for hardcase)

  //std::cout << "hardcase volume is " << hardcase.volume() << std::endl;
  //Box* box_pointer{ &hardcase };
  //std::cout << "hardcase volume through a Box* pointer is "
  //          << box_pointer->volume() << std::endl;
}

