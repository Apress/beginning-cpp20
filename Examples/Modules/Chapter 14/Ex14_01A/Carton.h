// Carton.h - defines the Carton class with the Box class as private base
#ifndef CARTON_H
#define CARTON_H

#include <string>
#include <string_view>
#include "Box.h"

class Carton : private Box
{
public:
  explicit Carton(std::string_view mat = "Cardboard") : m_material {mat} {}
  using Box::volume; // Inherit as public

private:
  std::string m_material;
};

#endif
