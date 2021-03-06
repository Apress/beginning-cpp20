// Carton.h - defines the Carton class with the Box class as base
#ifndef CARTON_H
#define CARTON_H

#include <string>
#include <string_view>
#include "Box.h"

class Carton : public Box
{
public:
  Carton() = default;

  Carton(double side, std::string_view material) : Box{side}, m_material{material}
  { std::cout << "Carton(double,string_view) called.\n"; }

  Carton(double l, double w, double h, std::string_view material)
    : Box{l, w, h}, m_material{material}
    { std::cout << "Carton(double,double,double,string_view) called.\n"; }  

private:
  std::string m_material {"Cardboard"};
};

#endif
