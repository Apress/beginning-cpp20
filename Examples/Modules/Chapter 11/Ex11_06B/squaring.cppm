export module squaring;

export namespace math         // Exports all nested declarations at once
{
  const double sqrt2{ 1.414213562373095 };       // the square root of 2
  auto square(const auto& x) { return x * x; }
  auto pow4(const auto& x) { return square(square(x)); }
}