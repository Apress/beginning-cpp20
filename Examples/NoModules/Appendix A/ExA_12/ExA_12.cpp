// Using inline definitions to prevent ODR violations when
// including a header in multiple translation units of the same program.
#include <iostream>
#include "Hypot.h"
#include "Pow4.h"

int main()
{
  std::cout << math::hypot(3, 4) << '\t' << math::pow4(5) << std::endl;
}
