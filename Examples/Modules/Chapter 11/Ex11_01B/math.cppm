export module math;

export
{
  auto square(const auto& x);

  const double lambda = 1.303577269034296391257;  // Conway's constant

  enum class Oddity { Even, Odd };
  auto getOddity(int x);
}

// The implementation of the module's functions (+ local helpers)
auto square(const auto& x) { return x * x; }

bool isOdd(int x) { return x % 2 != 0; }
auto getOddity(int x) { return isOdd(x) ? Oddity::Odd : Oddity::Even; }
