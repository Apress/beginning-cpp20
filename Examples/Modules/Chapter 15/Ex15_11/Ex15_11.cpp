// Using an interface class and indirect base classes
#include <iostream>
#include <vector>                     // For the vector container
#include "Box.h"                      // For the Box class
#include "ToughPack.h"                // For the ToughPack class
#include "Carton.h"                   // For the Carton class
#include "Can.h"                      // for the Can class

int main()
{
  Box box {40, 30, 20};
  Can can {10, 3};
  Carton carton {40, 30, 20, "Plastic"};
  ToughPack hardcase {40, 30, 20};

  std::vector<const Vessel*> vessels {&box, &can, &carton, &hardcase};

  for (const auto* vessel : vessels)
    std::cout << "Volume is " << vessel->volume() << std::endl;
}
