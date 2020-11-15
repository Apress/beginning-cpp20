#ifndef BOX_H
#define BOX_H
#include <iostream>

class Box
{
public:
  Box(double length, double width, double height)
    : m_length {length}, m_width {width}, m_height {height}
  {
    std::cout << "Box constructor called for a Box of volume " << volume() << std::endl;
  }
  virtual ~Box()
  {
    std::cout << "Box destructor called for a Box of volume " << volume() << std::endl;
  }

  // Function to calculate volume of a Box
  virtual double volume() const { return m_length * m_width * m_height; }

  void showVolume() const
  {
    std::cout << "The volume from inside Box::showVolume() is "
              << volume() << std::endl;
  }

private:
  double m_length, m_width, m_height;
};

#endif