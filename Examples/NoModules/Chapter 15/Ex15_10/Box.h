#ifndef BOX_H
#define BOX_H
#include <iostream>

class Box
{
public:
  Box(double l, double w, double h) : m_length {l}, m_width {w}, m_height {h} {}
  virtual ~Box() = default;            // Virtual destructor
  virtual double volume() const = 0;   // Function to calculate the volume

protected:  // Should be private in production-quality code (add getters to access)
  double m_length, m_width, m_height;
};

#endif
