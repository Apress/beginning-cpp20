// Carton.h - defines the Carton class with the Box class as base
#ifndef CARTON_H
#define CARTON_H

#include <string>
#include <string_view>
#include "Box.h"

class Carton : public Box
{
public:
  explicit Carton(std::string_view material = "Cardboard")  // Constructor
    : m_material{material} {}

private:
  std::string m_material;
};

#endif
