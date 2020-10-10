// Using the explicit keyword
// Uncomment "explicit" to make the compilation of 
// the expression "box1.hasLargerVolumeThan(50.0)" fail
#include <iostream>

class Cube
{
public:
  /*explicit*/ Cube(double side);       // Constructor
  double volume();                      // Calculate volume of a cube
  bool hasLargerVolumeThan(Cube cube);  // Compare volume of a cube with another
private:
  double m_side;
};

Cube::Cube(double side) : m_side{ side }
{
  std::cout << "Cube constructor called." << std::endl;
}

double Cube::volume() { return m_side * m_side * m_side; }
bool Cube::hasLargerVolumeThan(Cube cube) { return volume() > cube.volume(); }

int main()
{
  Cube box1{ 7.0 };
  Cube box2{ 3.0 };
  if (box1.hasLargerVolumeThan(box2))
    std::cout << "box1 is larger than box2." << std::endl;
  else
    std::cout << "Volume of box1 is less than or equal to that of box2." << std::endl;

  std::cout << "Volume of box1 is " << box1.volume() << std::endl;
  if (box1.hasLargerVolumeThan(50.0))
    std::cout << "Volume of box1 is greater than 50" << std::endl;
  else
    std::cout << "Volume of box1 is less than or equal to 50" << std::endl;
}
