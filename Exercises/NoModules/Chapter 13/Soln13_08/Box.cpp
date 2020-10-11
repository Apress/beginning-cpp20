#include "Box.h"

#include <format>
#include <cmath>    // For the min() and max() function templates

double Box::volume() const
{
    return m_length * m_width * m_height;
}

// Overloaded += operator
Box& Box::operator+=(const Box& aBox)
{
  // New object has larger length and width, and sum of heights
  m_length = std::max(m_length, aBox.m_length);
  m_width = std::max(m_width, aBox.m_width);
  m_height += aBox.m_height;
  return *this;
}

// Function to add two Box objects
Box Box::operator+(const Box& aBox) const
{
  Box copy{ *this };
  copy += aBox;
  return copy;
}

std::partial_ordering Box::operator<=>(const Box& aBox) const
{
  return volume() <=> aBox.volume();
}

std::partial_ordering Box::operator<=>(double value) const
{
  return volume() <=> value;
}

std::ostream& operator<<(std::ostream& stream, const Box& box)
{
  stream << std::format("Box({:.1f}, {:.1f}, {:.1f})",
                          box.getLength(), box.getWidth(), box.getHeight());
  return stream;
}