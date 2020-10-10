// Using a friend function of a class
#include <iostream>
#include <memory>
#include "Box.h"

int main()
{
  Box box1 {2.2, 1.1, 0.5};    // An arbitrary box
  Box box2;                    // A default box
  auto box3{ std::make_unique<Box>(15.0, 20.0, 8.0) }; // Dynamically allocated Box

  std::cout << "Volume of box1 = " << box1.volume() << std::endl;
  std::cout << "Surface area of box1 = " << surfaceArea(box1) << std::endl;

  std::cout << "Volume of box2 = "<< box2.volume() << std::endl;
  std::cout << "Surface area of box2 = " << surfaceArea(box2) << std::endl;

  std::cout << "Volume of box3 = " << box3->volume() << std::endl;
  std::cout << "Surface area of box3 = " << surfaceArea(*box3) << std::endl;
}

// friend function to calculate the surface area of a Box object
double surfaceArea(const Box& box)
{
  return 2.0 * (box.m_length * box.m_width
    + box.m_length * box.m_height + box.m_height * box.m_width);
}
