#ifndef BOX_H
#define BOX_H

class Box
{
public:
  Box();                     // Default constructor  
  Box(double side);          // Constructor for a cube
  Box(const Box& box);       // Copy constructor
  Box(double length, double width, double height);
  ~Box();   // Destructor

  double volume() const { return m_length * m_width * m_height; }

  static size_t getObjectCount() { return s_object_count; }

private:
  double m_length {1.0};
  double m_width {1.0};
  double m_height {1.0};
  static inline size_t s_object_count {};   // Count of objects ever created
};

#endif
