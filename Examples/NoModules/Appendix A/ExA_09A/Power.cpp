// A local helper function with internal linkage 
namespace
{
  double localHelper(double x, unsigned n)   // localHelper() has internal linkage 
  {
    if (n == 0) return 1.0;                  // Recursion base case
    const double y{ localHelper(x, n / 2) }; // See Exercise 8-8 for an explanation
    return y * y * (n % 2 == 1 ? x : 1.0); 
  }
}

double power(double x, int n)               // power() has external linkage
{
  return n >= 0 ? localHelper(x, static_cast<unsigned>(n))
                : 1.0 / localHelper(x, static_cast<unsigned>(-n));
}
