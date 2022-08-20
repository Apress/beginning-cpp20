export module boxes:box;

import vessel;

export class Box : public Vessel
{
public:
  Box(double l, double w, double h) : m_length {l}, m_width {w}, m_height {h} {}

  double getLength() const { return m_length; }
  double getWidth() const { return m_width; }
  double getHeight() const { return m_height; }

  double volume() const override { return m_length * m_width * m_height; }

private:
  double m_length, m_width, m_height;
};
