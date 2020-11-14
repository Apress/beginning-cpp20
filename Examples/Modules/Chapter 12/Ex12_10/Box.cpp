module box;
import <iostream>;

// Constructor definition
Box::Box(double length, double width, double height)
  : m_length{ length }, m_width{ width }, m_height{ height }
{
  std::cout << "Box constructor called." << std::endl;
}

// Const member function definition
double Box::volume() const
{
  return m_length * m_width * m_height;
}
