// Cerealpack.h - Class defining a carton of cereal
#ifndef CEREALPACK_H
#define CEREALPACK_H
#include <iostream>
#include "Carton.h"
#include "FoodContainer.h"

class CerealPack : public Carton, public FoodContainer
{
public:
  CerealPack(double length, double width, double height, std::string_view cerealType)
    : Carton {length, width, height, "Chipboard"}, FoodContainer {cerealType}
  {
    std::cout << "CerealPack constructor" << std::endl;
    FoodContainer::volume = 0.9 * Carton::volume();   // Set food container's volume
  }

  ~CerealPack()
  {
    std::cout << "CerealPack destructor" << std::endl;
  }

  using Carton::volume;
  using FoodContainer::getWeight;
};

#endif
