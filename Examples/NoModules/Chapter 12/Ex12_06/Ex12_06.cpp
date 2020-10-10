// Defining classes in separate files.
// Without modules, this normally means the class is defined in a header file,
// and the member functions in source file. To mirror the book's exercise, though,
// here we define all members in the header as well (as inline functions).
// See online Appendix A for details.
#include "Box.h"
#include <iostream>

int main()
{
  Box firstBox {80.0, 50.0, 40.0};            // Create a box
  double firstBoxVolume {firstBox.volume()};  // Calculate the box volume
  std::cout << "Volume of Box object is " << firstBoxVolume << std::endl;
}
