module box;

import <iostream>;

Box::Box(double length, double width, double height)  // Constructor definition
  : m_length{length}, m_width{width}, m_height{height}
{
  std::cout << "Box constructor 1 called." << std::endl;
}

Box::Box(double side) : Box{side, side, side}  // Constructor for a cube
{
  std::cout << "Box constructor 2 called." << std::endl;
}

Box::Box()                                      // Default constructor
{
  std::cout << "Default Box constructor called." << std::endl;
}

Box::Box(const Box& box)                        // Copy constructor
  : m_length{box.m_length}, m_width{box.m_width}, m_height{box.m_height}
{
  std::cout << "Box copy constructor called." << std::endl;
}
