module box;

import <format>;
import <algorithm>;    // For the min() and max() function templates

double Box::volume() const
{
    return m_length * m_width * m_height;
}

Box Box::operator+(const Box& aBox) const
{
  Box copy{ *this };  // Implement in terms of += operator (avoid duplication)
  copy += aBox;
  return copy;        // Return new object (convention)
}

Box Box::operator*(double factor) const
{
  Box copy{ *this };  // Implement in terms of *= operator (avoid duplication)
  copy *= factor;
  return copy;        // Return new object (convention)
}

Box Box::operator/(double divisor) const
{
  Box copy{ *this };  // Implement in terms of /= operator (avoid duplication)
  copy /= divisor;
  return copy;        // Return new object (convention)
}

Box& Box::operator+=(const Box& aBox)
{
  // New object has larger length and width, and sum of heights
  m_length = std::max(m_length, aBox.m_length);
  m_width  = std::max(m_width, aBox.m_width);
  m_height += aBox.m_height;
  return *this;   // Return a reference to the left operand (convention)
}

Box& Box::operator*=(double factor)
{
  m_length *= factor;
  m_width  *= factor;
  m_height *= factor;
  return *this;   // Return a reference to the left operand (convention)
}

Box& Box::operator/=(double divisor)
{
  m_length /= divisor;
  m_width  /= divisor;
  m_height /= divisor;
  return *this;   // Return a reference to the left operand (convention)
}

Box operator*(double factor, const Box& box)
{
  return box * factor;
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