export module math;

bool isOdd(int x) { return x % 2 != 0; }   // Module-local function (not exported)

export
{
  auto square(const auto& x) { return x * x; }

  const double lambda = 1.303577269034296391257;  // Conway's constant

  enum class Oddity { Even, Odd };
  auto getOddity(int x) { return isOdd(x) ? Oddity::Odd : Oddity::Even; }
}
