#ifndef BOX_H
#define BOX_H

class Box
{
public:
  Box() : Box{ 1.0, 1.0, 1.0} {}        // A delegating default constructor
  Box(double length, double width, double height);

  double volume() const;                // Function to calculate the volume of a box

  friend double surfaceArea(const Box& box); // Friend function for the surface area

private:
  double m_length, m_width, m_height;
};

#endif
