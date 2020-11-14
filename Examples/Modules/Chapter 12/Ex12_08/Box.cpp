#include <iostream>
#include "Box.h"

// Constructor definition
Box::Box(double length, double width, double height)
  : m_length{ length }, m_width{ width }, m_height{ height }
{
  std::cout << "Box constructor called." << std::endl;
}

// Member function definition
double Box::volume()
{
  return m_length * m_width * m_height;
}

// Mutator function definitions
Box& Box::setLength(double length)
{
  if (length > 0) m_length = length;
  return *this;
}
Box& Box::setWidth(double width)
{
  if (width > 0) m_width = width;
  return *this;
}
Box& Box::setHeight(double height)
{
  if (height > 0) m_height = height;
  return *this;
}
