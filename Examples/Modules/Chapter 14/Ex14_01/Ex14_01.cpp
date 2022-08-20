// Defining and using a derived class
#include <print>
import box;
import carton;

int main()
{
  // Create a Box object and two Carton objects
  Box box {40.0, 30.0, 20.0};
  Carton carton;
  Carton chocolateCarton {"Solid bleached board"};  // Good old SBB
  // Check them out - sizes first of all
  std::println("box occupies {} bytes", sizeof box);
  std::println("carton occupies {} bytes", sizeof carton);
  std::println("candyCarton occupies {} bytes", sizeof chocolateCarton);

  // Now volumes...
  std::println("box volume is {}", box.volume());
  std::println("carton volume is {}", carton.volume());
  std::println("chocolateCarton volume is {}", chocolateCarton.volume());

  std::println("chocolateCarton length is {}", chocolateCarton.getLength());

  // Uncomment any of the following for an error...
  // box.m_length = 10.0;
  // chocolateCarton.m_length = 10.0;
}
