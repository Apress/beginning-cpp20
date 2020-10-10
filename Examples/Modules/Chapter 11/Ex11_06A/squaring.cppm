export module squaring;

namespace math
{
  export const double sqrt2{ 1.414213562373095 };      // the square root of 2
  export auto square(const auto& x) { return x * x; }
  export auto pow4(const auto& x) { return square(square(x)); }
}