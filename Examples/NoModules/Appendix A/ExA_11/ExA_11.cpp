// Creating multiple definitions of the same functions in a program,
// even though #include guards are present.
// (The guards only prevent multiple definitions within one translation unit!)
#include <iostream>
#include "Hypot.h"
#include "Pow4.h"

int main()
{
  std::cout << math::hypot(3, 4) << '\t' << math::pow4(5) << std::endl;
}
