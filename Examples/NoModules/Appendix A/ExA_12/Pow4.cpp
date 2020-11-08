// Definition of the math::pow4() function
#include "ProperMath.h"  // For the square() function template definition

namespace math
{
  double pow4(double x) { return square(square(x)); }
}
