#ifndef TOUGH_PACK_H
#define TOUGH_PACK_H

#include "Box.h"

class ToughPack : public Box
{
public:
  ToughPack(double length, double width, double height)
    : Box{length, width, height}
  {
    std::cout << "ToughPack constructor called for a Box of volume "
              << volume() << std::endl;
  }
  virtual ~ToughPack()
  {
    std::cout << "ToughPack destructor called for a Box of volume "
              << volume() << std::endl;
  }

  // Function to calculate volume of a ToughPack allowing 15% for packing
  double volume() const override { return 0.85 * Box::volume(); }
};

#endif