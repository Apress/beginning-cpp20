#include <cmath>      // For std::sqrt()
#include <numbers>    // For std::numbers::sqrt2 

/* Re-export two existing entities from the math namespace using using declarations */
namespace math        // Exports all nested declarations at once
{
  using std::numbers::sqrt2;
  using std::sqrt;    // Never 'using std::sqrt();' or 'using std::sqrt(double);'!
  auto square(const auto& x) { return x * x; }
  auto pow4(const auto& x) { return square(square(x)); }
}

/* Export all names from a namespace from the math namespace using a using directive */
//namespace math
//{
//  export using namespace std::numbers;
//}