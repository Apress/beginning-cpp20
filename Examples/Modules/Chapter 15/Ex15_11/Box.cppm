export module boxes:box;

import vessel;

export class Box : public Vessel
{
public:
  Box(double l, double w, double h) : m_length {l}, m_width {w}, m_height {h} {}

  double volume() const override { return m_length * m_width * m_height; }

protected:   // Should be private in production-quality code (add getters to access)
  double m_length, m_width, m_height;
};
