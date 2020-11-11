// Inline class member definitions
#ifndef BOX_H
#define BOX_H

#include <ostream>   // Caution: do not use import <ostream>; here!

class Box
{
public:
  Box() = default;   // In-class definition, and thus implicitly inline
  Box(double length, double width, double height);
  
  // In-class member definitions are implicitly inline
  double getLength() const { return m_length; };
  double getWidth() const  { return m_width; };
  double getHeight() const { return m_height; };
  
  double volume() const;

private:
  double m_length {1.0};
  double m_width {1.0};
  double m_height {1.0};
};

// Out-of-class member definitions must be explicitly marked as inline 
inline Box::Box(double length, double width, double height)
  : m_length{ length }, m_width{ width }, m_height{ height }
{}

inline double Box::volume() const
{
  return m_length * m_width * m_height;
}

// Definitions of non-member functions of course must be inline as well
inline std::ostream& operator<<(std::ostream& out, const Box& box)
{
  return out << "Box(" << box.getLength() << ", " 
             << box.getWidth() << ", " << box.getHeight() << ')';
}

#endif
