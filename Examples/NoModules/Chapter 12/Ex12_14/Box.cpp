#include <iostream>
#include "Box.h"

Box::Box(double length, double width, double height)  // Constructor definition
  : m_length{length}, m_width{width}, m_height{height}
{
  ++s_object_count;
  std::cout << "Box constructor 1 called." << std::endl;
}

Box::Box(double side) : Box{side, side, side}  // Constructor for a cube
{
  // Do not increment s_object_count in forwarding constructor: 
  // already incremented in the constructor this constructor forwards to!
  std::cout << "Box constructor 2 called." << std::endl;
}

Box::Box()                                      // Default constructor
{
  ++s_object_count;
  std::cout << "Default Box constructor called." << std::endl;
}

Box::Box(const Box& box)                        // Copy constructor
  : m_length{box.m_length}, m_width{box.m_width}, m_height{box.m_height}
{
  ++s_object_count;
  std::cout << "Box copy constructor called." << std::endl;
}
