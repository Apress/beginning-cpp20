// Using a member initializer list
#include <iostream>

// Class to represent a box
class Box
{
public:
  Box() = default;
  Box(double length, double width, double height);

  double volume();   // Function to calculate the volume of a box

private:
  double m_length{ 1.0 };
  double m_width{ 1.0 };
  double m_height{ 1.0 };
};

int main()
{
  Box firstBox {80.0, 50.0, 40.0};            // Create a box
  double firstBoxVolume {firstBox.volume()};  // Calculate the box volume
  std::cout << "Volume of Box object is " << firstBoxVolume << std::endl;

  Box secondBox;        // No longer causes a compiler error message
}

// Constructor definition
Box::Box(double length, double width, double height)
  : m_length{length}, m_width{width}, m_height{height}
{
  std::cout << "Box constructor called." << std::endl;
}

// Member function definition
double Box::volume()
{
  return m_length * m_width * m_height;
}
