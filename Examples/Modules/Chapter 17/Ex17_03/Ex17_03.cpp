// Illustrating Class Template Argument Deduction (CTAD) 
// by adding an initializer list constructor to our Array<> template.
#include "Box.h"
#include "Array.h"
#include <iostream>

int main()
{
  // Class Template Argument Deduction (CTAD) in action:
  Array integers{ 1, 2, 3, 4, 5 };           // Deduced type: Array<int>
  Array doubles{ 1.0, 2.0, 3.0, 4.0, 5.0 };  // Deduced type: Array<double

  // But... caution!
  {
    const size_t numValues{ 50 };
    Array<double> values{ numValues };  // Now uses the initializer list constructor!

    std::cout << "Wrong constructor used, so " << values.getSize() << " != " << numValues << std::endl;
    std::cout << "Single value contained in Array<> is " << values[0] << std::endl;
  }

  // Workaround: do not use uniform initialization (or "near uniform", as is thus more appropriate...)
  { 
    const size_t numValues{ 50 };
    Array<double> values(numValues);    // Uses Array(size_t) constructor as before

    std::cout << "Intended constructor used, so " << values.getSize() << " == " << numValues << std::endl;
    std::cout << "All values are equal to " << values[numValues / 2] << std::endl;
  }
}
