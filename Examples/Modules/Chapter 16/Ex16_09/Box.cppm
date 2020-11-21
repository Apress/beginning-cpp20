export module box;
import <algorithm>;                        // For std::min() function template
import dimension_error;

export class Box
{
public:
  Box(double l, double w, double h) : m_length{ l }, m_width{ w }, m_height{ h }
  {
    if (l <= 0.0 || w <= 0.0 || h <= 0.0)
      throw DimensionError{ std::min({l, w, h}) };
  }

  double volume() const { return m_length * m_width * m_height; }
private:
  double m_length{ 1.0 };
  double m_width{ 1.0 };
  double m_height{ 1.0 };
};
