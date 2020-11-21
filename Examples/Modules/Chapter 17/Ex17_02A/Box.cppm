export module box;

export class Box
{
public:
  Box() : Box{ 1.0, 1.0, 1.0 } {};
  Box(double l, double w, double h) : m_length{ l }, m_width{ w }, m_height{ h } {}

  double volume() const { return m_length * m_width * m_height; }
private:
  double m_length, m_width, m_height;
};
