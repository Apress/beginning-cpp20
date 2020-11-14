#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box
{
public:
  // Constructors
  Box() = default;
  Box(double length, double width, double height);

  double volume() const;    // Const function to calculate the volume of a box

  // Non-const overloads (return references to dimension variable)
  double& length() { std::cout << "non-const overload called\n"; return m_length; };
  double& width()  { std::cout << "non-const overload called\n"; return m_width; };
  double& height() { std::cout << "non-const overload called\n"; return m_height; };

  // Const overloads (return references to const variables)
  const double& length() const { std::cout << "const overload called\n"; return m_length; };
  const double& width()  const { std::cout << "const overload called\n"; return m_width; };
  const double& height() const { std::cout << "const overload called\n"; return m_height; };

  // Attempt to return non-const references to member variables from const functions
// double& length() const { return m_length; };   // This must not be allowed to compile!
// double& width()  const { return m_width; };
// double& height() const { return m_height; };

private:
  double m_length{1.0};
  double m_width {1.0};
  double m_height{1.0};
};

#endif
