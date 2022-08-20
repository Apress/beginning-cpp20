// Behavior of inherited functions in a derived class
import boxes;

#include <print>

int main()
{
  Box box {20.0, 30.0, 40.0};            // Create a box
  ToughPack hardcase {20.0, 30.0, 40.0}; // Create a tough pack - same size

  box.printVolume();      // Display volume of base box (calls volume() for box)
  hardcase.printVolume(); // Display volume of derived box (call volume() for hardcase)

  // std::println("hardcase volume is {}", hardcase.volume());
  // Box* hardcaseBox{ &hardcase };
  // std::println("hardcase volume through a Box* pointer is {}", hardcaseBox->volume());
}
