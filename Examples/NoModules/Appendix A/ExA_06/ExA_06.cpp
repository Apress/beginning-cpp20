// Defining the same function twice (won't compile!)
#include <iostream>
#include <format>

double power(double x, int n);
double power(double x, int n);  // Redundant declaration (harmless)

int main()
{
  for (int i{ -3 }; i <= 3; ++i)    // Calculate powers of 8 from -3 to +3
    std::cout << std::format("{:10}\n", power(8.0, i));
  std::cout << std::endl;
}

double power(double x, int n)   // A first definition
{
  if (n == 0)      return 1.0;
  else if (n > 0)  return x * power(x, n - 1);
  else /* n < 0 */ return 1.0 / power(x, -n);
}

double power(double x, int n);  // Another redundant declaration (harmless)

double power(double x, int n)   // A second, more efficient definition (error!)
{
  if (n < 0)  return 1.0 / power(x, -n); // Deal with negative exponents
  if (n == 0) return 1.0;                // Base case of the recursion
  const double y{ power(x, n / 2) };     // See Exercise 8-8 for an explanation
  return y * y * (n % 2 == 1 ? x : 1.0);
}
