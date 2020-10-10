#include <iostream>
#include "Box.h"

// Constructor definition
Box::Box(double length, double width, double height)
  : m_length{ length }, m_width{ width }, m_height{ height }
{
  std::cout << "Box constructor called." << std::endl;
}

// Const member function definition
double Box::volume() const
{
  return m_length * m_width * m_height;
}

// Modify mutable member variable from a const member function 
void Box::printVolume() const
{
  // Count how many times printVolume() is called using a mutable member in a const function
  std::cout << "The volume of this box is " << volume() << std::endl;
  std::cout << "printVolume() has been called " << ++m_count << " time(s)" << std::endl;
}
