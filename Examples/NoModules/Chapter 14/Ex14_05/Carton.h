// Carton.h - defines the Carton class with the Box class as base
#ifndef CARTON_H
#define CARTON_H

#include <string>
#include <string_view>
#include "Box.h"

class Carton : public Box
{
  using Box::Box;  // Inherit Box class constructors 

public:
  Carton(double length, double width, double height, std::string_view mat)
     : Box{length, width, height}, m_material{mat}
     { std::cout << "Carton(double,double,double,string_view) called.\n"; }

private:
  std::string m_material {"Cardboard"};
};

#endif
