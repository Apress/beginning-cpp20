// Exercise 8_8 More efficient recursive version of function for x to the power n, n positive or negative
// Based on Ex8_17.cpp
#include <iostream>
#include <iomanip>

long double power(double x, int n);

int main()
{
  for (int i {-3}; i <= 3; ++i)     // Calculate powers of 8 from -3 to +3
    std::cout << std::setw(10) << power(8.0, i);

  std::cout << std::endl;
}

// Recursive function to calculate x to the power n
long double power(double x, int n)
{
  if (n == 0)     return 1.0;
  else if (n < 0) return 1.0 / power(x, -n);
  else if (n % 2) return x * power(x, n-1);     // x is odd
  
  // If we make it this far, x > 0 and even
  const auto y = power(x, n/2); 
  return y * y;
}