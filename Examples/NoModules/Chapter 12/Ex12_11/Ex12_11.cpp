// Const objects and const member functions
#include "Box.h"
#include <iostream>

int main()
{
  const Box myBox {3.0, 4.0, 5.0};
  std::cout << "myBox dimensions are " << myBox.getLength()
            << " by " << myBox.getWidth()
            << " by " << myBox.getHeight() << std::endl;

  myBox.printVolume();
  myBox.printVolume();
  myBox.printVolume();
}
