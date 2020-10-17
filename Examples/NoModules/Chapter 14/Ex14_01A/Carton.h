// Carton.h - defines the Carton class with the Box class as base
#ifndef CARTON_H
#define CARTON_H
#include <string>
#include <string_view>
#include "Box.h"

class Carton : private Box
{
private:
  std::string material;

public:
  using Box::volume;                              // Inherit as public
  explicit Carton(std::string_view mat = "Cardboard") : material {mat} {}     // Constructor
};
#endif
