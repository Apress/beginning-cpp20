#ifndef BOX_H
#define BOX_H

class Box
{
public:
  /* Constructors */
  Box(double length, double width, double height);
  Box(double side);       // Constructor for a cube
  Box();                  // Default constructor
  Box(const Box& box);    // Copy constructor

  double volume() const { return m_length * m_width * m_height; };

private:
  double m_length {1.0};
  double m_width {1.0};
  double m_height {1.0};
};

#endif
