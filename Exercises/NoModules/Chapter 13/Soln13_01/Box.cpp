#include "Box.h"

#include <format>
#include <algorithm>    // For the min() and max() function templates

double Box::volume() const
{
    return m_length * m_width * m_height;
}

Box Box::operator+(const Box& aBox) const
{
  // New object has larger length and width, and sum of heights
  return Box{ std::max(m_length, aBox.m_length),
              std::max(m_width, aBox.m_width),
              m_height + aBox.m_height };
}

Box Box::operator*(double factor) const
{
  return Box{ m_length * factor, m_width * factor, m_height * factor, };
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