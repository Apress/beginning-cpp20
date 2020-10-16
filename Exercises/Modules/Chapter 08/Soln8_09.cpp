// Exercise 8_9 Count the number of multiplications performed by 
// the divide and conquer power() function of Soln8_08.cpp
import <iostream>;
import <iomanip>;

long double power(double x, int n);

int main()
{
  std::cout << power(1.5, 1000) << std::endl;
}

inline auto mult(long double l, long double r)
{
  static size_t count{};
  std::cout << ++count << " multiplications" << std::endl;
  return l * r;
}

// Recursive function to calculate x to the power n
long double power(double x, int n)
{
  if (n == 0)     return 1.0;
  else if (n < 0) return 1.0 / power(x, -n);
  else if (n % 2) return mult(x, power(x, n - 1));     // x is odd
  
  // If we make it this far, x > 0 and even
  const auto y{ power(x, n / 2) };
  return mult(y, y);
}