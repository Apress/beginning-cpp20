// Defining and using a namespace

import <iostream>;
import <numbers>;

namespace math
{
  const double sqrt2{ 1.414213562373095 };      // the square root of 2
  auto square(const auto& x) { return x * x; }
  auto pow4(const auto& x) { return square(square(x)); }
}

int main()
{
  std::cout << "math::sqrt2 has the value " << math::sqrt2 << std::endl;
  std::cout << "This should be 0: " << (math::sqrt2 - std::numbers::sqrt2) << std::endl;
  std::cout << "This should be 2: " << math::square(math::sqrt2) << std::endl;
}
