// Module interface file for a module exporting the Box class
export module box;
import <iostream>;

// Class to represent a box
export class Box
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

// Constructor definition
Box::Box(double length, double width, double height)
  : m_length{ length }, m_width{ width }, m_height{ height }
{
  std::cout << "Box constructor called." << std::endl;
}

// Member function definition
double Box::volume() { return m_length * m_width * m_height; }
