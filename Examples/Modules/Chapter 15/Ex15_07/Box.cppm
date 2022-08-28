export module boxes:box;

import <print>;

export class Box
{
public:
  Box() : Box{ 1.0, 1.0, 1.0 } {}
  Box(double l, double w, double h) : m_length {l}, m_width {w}, m_height {h} {}

  ~Box() { std::println("Box destructor called"); }

  // Function to print the usable volume of a Box object
  void printVolume() const
  { std::println("Box usable volume is {}", volume()); }

  // Function to calculate the volume of a Box object
  virtual double volume() const { return m_length * m_width * m_height; }

  double getLength() const { return m_length; }
  double getWidth() const { return m_width; }
  double getHeight() const { return m_height; }

private:
  double m_length, m_width, m_height;
};
