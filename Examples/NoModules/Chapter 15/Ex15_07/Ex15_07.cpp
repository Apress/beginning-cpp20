// Polymorphic vectors of smart pointers
#include <iostream>
#include <memory>                                // For smart pointers
#include <vector>                                // For vector
#include "Box.h"                                 // For the Box class
#include "ToughPack.h"                           // For the ToughPack class
#include "Carton.h"                              // For the Carton class

int main()
{
  // Careful: this first attempt at a mixed collection is a bad idea (object slicing!)
  std::vector<Box> boxes;
  boxes.push_back(Box{20.0, 30.0, 40.0});
  boxes.push_back(ToughPack{20.0, 30.0, 40.0});
  boxes.push_back(Carton{20.0, 30.0, 40.0, "plastic"});

  for (const auto& p : boxes)
    p.showVolume();

  std::cout << std::endl;
  
  // Next, we create a proper polymorphic vector<>:
  std::vector<std::unique_ptr<Box>> polymorphicBoxes;
  polymorphicBoxes.push_back(std::make_unique<Box>(20.0, 30.0, 40.0));
  polymorphicBoxes.push_back(std::make_unique<ToughPack>(20.0, 30.0, 40.0));
  polymorphicBoxes.push_back(std::make_unique<Carton>(20.0, 30.0, 40.0, "plastic"));

  for (const auto& p : polymorphicBoxes)
    p->showVolume();
}
