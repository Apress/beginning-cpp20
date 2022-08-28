export module boxes:box;

import <print>;

export class Box
{
public:
  Box(double length, double width, double height)
    : m_length {length}, m_width {width}, m_height {height}
  {
    std::println("Box constructor called for a Box of volume {}", volume());
  }
  virtual ~Box()
  {
    std::println("Box destructor called for a Box of volume {}", volume());
  }

  // Function to calculate volume of a Box
  virtual double volume() const { return m_length * m_width * m_height; }

  void printVolume() const
  {
    std::println("The volume from inside Box::printVolume() is {}", volume());
  }

private:
  double m_length, m_width, m_height;
};

