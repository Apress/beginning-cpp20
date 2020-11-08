// The power function called from ExA_07.cpp is defined in a different translation unit
double power(double x, int n)
{
  if (n < 0) return 1.0 / power(x, -n); // Deal with negative exponents
  if (n == 0) return 1.0;               // Recursion base case
  const double y{ power(x, n / 2) };    // See Exercise 8-8 for an explanation
  return y * y * (n % 2 == 1 ? x : 1.0);
}
