// Defining a default constructor
import <iostream>;

// Class to represent a box
class Box
{
public:
// Box() {}           // Explicitly defined default constructor
  Box() = default;    // Defaulted default constructor

  // Constructor
  Box(double length, double width, double height)
  {
    std::cout << "Box constructor called."  << std::endl;
    m_length = length;
    m_width = width;
    m_height = height;
  }

  // Function to calculate the volume of a box
  double volume()
  {
    return m_length * m_width * m_height;
  }

private:
  double m_length {1.0};
  double m_width {1.0};
  double m_height {1.0};
};

int main()
{
  Box firstBox {80.0, 50.0, 40.0};            // Create a box
  double firstBoxVolume {firstBox.volume()};  // Calculate the box volume
  std::cout << "Volume of Box object is " << firstBoxVolume << std::endl;

  Box secondBox;        // No longer causes a compiler error message
}
