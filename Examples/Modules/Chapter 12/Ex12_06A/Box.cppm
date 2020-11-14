export module box;

// Class to represent a box
export class Box
{
public:
  Box() = default;
  Box(double length, double width, double height);

  double volume();   // Function to calculate the volume of a box

private:
  double m_length{ 1.0 };
  double m_width{ 1.0 };
  double m_height{ 1.0 };
};
