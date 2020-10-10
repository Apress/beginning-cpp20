export module math;

import <span>;

export namespace math
{
  auto square(const auto& x) { return x * x; };

  namespace averages
  {
    double arithmetic_mean(std::span<const double> data);
    double geometric_mean(std::span<const double> data);
    double rms(std::span<const double> data);
    double median(std::span<const double> data);
  }
}