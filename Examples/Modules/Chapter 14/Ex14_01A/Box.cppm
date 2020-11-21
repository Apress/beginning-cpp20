// Box.cppm - defines Box class
export module box;

export class Box
{
public:
  Box() = default;
  Box(double length, double width, double height)
      : m_length{ length }, m_width{ width }, m_height{ height }
  {}

  double volume() const { return m_length * m_width * m_height; }

  // Accessors
  double getLength() const { return m_length; }
  double getWidth()  const { return m_width; }
  double getHeight() const { return m_height; }

private:
  double m_length {1.0};
  double m_width  {1.0};
  double m_height {1.0};
};
