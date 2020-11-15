export module box;

import <compare>;  // For std::partial_ordering (see Chapter 4)
import <ostream>;  // For std::ostream

export class Box
{
public:
  Box() = default;       // Default constructor
  Box(double length, double width, double height)
    : m_length{ std::max(length,width) }
    , m_width { std::min(length,width) }
    , m_height{ height } 
  {}

  double volume() const; // Function to calculate the volume
  
  // Accessors
  double getLength() const { return m_length; }
  double getWidth() const  { return m_width; }
  double getHeight() const { return m_height; }

  // Functions that add full support for comparison operators
  std::partial_ordering operator<=>(const Box& aBox) const;
  std::partial_ordering operator<=>(double value) const;
  bool operator==(const Box& aBox) const = default;

  Box operator+(const Box& aBox) const; // Function to add two Box objects
  Box operator*(double factor) const;   // Function to multiply a Box with a given factor

private:
  double m_length {1.0};
  double m_width {1.0};
  double m_height {1.0};
};

export std::ostream& operator<<(std::ostream& stream, const Box& box);
