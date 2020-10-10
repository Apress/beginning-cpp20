// Using using declarations and using directives
#include <iostream>
#include "squaring.h"

/* Make names from the math namespace available locally */
auto my_hypot(const auto& x, const auto& y) // Renamed to my_hypot to avoid clashes with hypot() function in <cmath>
{
  using namespace math;
  // Or:
  //   using math::square;
  //   using math::sqrt;    /* Same as, of course: using std::sqrt; */
  return sqrt(square(x) + square(y));
}

int main()
{
  std::cout << "math::sqrt2 has the value " << math::sqrt2 << std::endl;
  std::cout << "This should be 0: " << (math::sqrt2 - std::numbers::sqrt2) << std::endl;
  std::cout << "This should be 2: " << math::square(math::sqrt2) << std::endl;
  std::cout << "This should be 5: " << my_hypot(3, 4) << std::endl;
}
