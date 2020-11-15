// Carton.h - defines the Carton class with the Box class as base
#ifndef CARTON_H
#define CARTON_H

#include <string>
#include <string_view>
#include "Box.h"

class Carton : public Box
{
public:
  Carton() { std::cout << "Carton() called.\n"; }

  explicit Carton(std::string_view material) : m_material{material}
  { std::cout << "Carton(string_view) called.\n"; }

  Carton(double side, std::string_view material) : Box{side}, m_material{material}
  { std::cout << "Carton(double,string_view) called.\n"; }

  Carton(double l, double w, double h, std::string_view material)
    : Box{l, w, h}, m_material{material}
    { std::cout << "Carton(double,double,double,string_view) called.\n"; } 

  // One new constructor
  Carton(double l, double w, double h, std::string_view m, double density, double thickness)
    : Carton{l, w, h, m} 
  {
    m_thickness = thickness; m_density = density;
    std::cout << "Carton(double,double,double,string_view,double,double) called.\n";
  }

  // Copy constructor
  Carton(const Carton& carton) : Box{carton}, m_material{carton.m_material},
     m_thickness{carton.m_thickness}, m_density{carton.m_density}
  {
    std::cout << "Carton copy constructor" << std::endl;
  }

  // Destructor
  ~Carton()
  {
    std::cout << "Carton destructor. Material = " << m_material << std::endl;
  }

  double getWeight() const
  {
    return 2.0 * (m_length * m_width + m_width * m_height + m_height * m_length) 
               * m_thickness * m_density;
  }

private:
  std::string m_material {"Cardboard"};
  double m_thickness {0.125};   // Material thickness in inch
  double m_density {0.2};       // Material density in pounds/cubic inch
};

#endif