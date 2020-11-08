// Your first header file with a class definition
#ifndef BOX_H
#define BOX_H

class Box
{
public:
  Box();
  Box(double length, double width, double height);

  double getLength() const;
  double getWidth() const;
  double getHeight() const;

  double volume() const;

private:
  double m_length;
  double m_width;
  double m_height;
};

#endif
