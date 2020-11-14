// Defining classes in separate files.
// Without modules, this normally means the class is defined in a header file,
// and the member functions in source file like we did for this example. 
// See online Appendix A for details.

#include <iostream>   // For use of std::cout, std::endl, etc.
#include "Box.h"      // For use of the Box class

int main()
{
  Box myBox{ 6.0, 6.0, 18.5 }; // Create a box
  std::cout << "Volume of the first Box object is " << myBox.volume() << std::endl;
}