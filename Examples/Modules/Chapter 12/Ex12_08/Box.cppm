#ifndef BOX_H
#define BOX_H

class Box
{
public:
  // Constructors
  Box() = default;
  Box(double length, double width, double height);

  double volume();    // Function to calculate the volume of a box

  // Inspector functions
  double getLength() { return m_length; }
  double getWidth()  { return m_width; }
  double getHeight() { return m_height; }

  // Mutator functions
  Box& setLength(double length);
  Box& setWidth(double width);
  Box& setHeight(double height);

private:
  double m_length{1.0};
  double m_width {1.0};
  double m_height{1.0};
};

#endif
