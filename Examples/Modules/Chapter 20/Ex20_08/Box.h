#ifndef BOX_H
#define BOX_H

// Class to represent a box
class Box
{
public:
  Box() = default;
  Box(double length, double width, double height)
    : m_length{ length }, m_width{ width }, m_height{ height }
  {}

  double getLength() const { return m_length; }
  double getWidth() const  { return m_width; }
  double getHeight() const { return m_height; }

  void setLength(double length) { if (length > 0) m_length = length; }
  void setWidth(double width)   { if (width > 0) m_width = width; }
  void setHeight(double height) { if (height > 0) m_height = height; }

  // Function to calculate the volume of a box
  double volume() const { return m_length * m_width * m_height; }

private:
  double m_length{ 1.0 };
  double m_width{ 1.0 };
  double m_height{ 1.0 };
};

#endif
