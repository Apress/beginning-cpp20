#ifndef BOX_H
#define BOX_H

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

// Constructor definition
// (inline because this member is defined in a header file: see online Appendix A)
inline Box::Box(double length, double width, double height)
  : m_length{ length }, m_width{ width }, m_height{ height }
{
  std::cout << "Box constructor called." << std::endl;
}

// Member function definition
// (inline because this member is defined in a header file: see online Appendix A)
inline double Box::volume()
{
  return m_length * m_width * m_height;
}

#endif
