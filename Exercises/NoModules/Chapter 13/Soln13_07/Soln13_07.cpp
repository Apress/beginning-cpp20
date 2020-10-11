// Exercise 13-7
// Rational operators
#include <iostream>
#include "Rational.h"

int main()
{
  Rational x{3, 4};
  Rational y{1, 2};
  
  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;
  
  std::cout << "x = " << static_cast<float>(x) << std::endl;
  std::cout << "y = " << static_cast<double>(y) << std::endl;
  
  std::cout << "-x = " << -x << std::endl;
  
  std::cout << "x + y = " << x + y << std::endl;
  std::cout << "x - y = " << x - y << std::endl;
  std::cout << "x * y = " << x * y << std::endl;
  std::cout << "x / y = " << x / y << std::endl;
  
  std::cout << "x + 2 = " << x + 2 << std::endl;
  std::cout << "3 - y = " << 3 - y << std::endl;
  std::cout << "x * 4 = " << x * 4 << std::endl;
  std::cout << "5 / y = " << 5 / y << std::endl;
  
  std::cout << std::boolalpha;  // Print true and false as "true" and "false" instead of "1" and "0"
  std::cout << "x < y = " << (x < y) << std::endl;
  std::cout << "x > y = " << (x > y) << std::endl;
  std::cout << "x == y = " << (x == y) << std::endl;
  std::cout << "x != y = " << (x != y) << std::endl;
  std::cout << "x >= y = " << (x >= y) << std::endl;
  std::cout << "x >= y = " << (x <= y) << std::endl;
  
  std::cout << "x < 1 = " << (x < 1) << std::endl;
  std::cout << "2 > y = " << (2 > y) << std::endl;
  std::cout << "x == 3 = " << (x == 3) << std::endl;
  std::cout << "4 != y = " << (4 != y) << std::endl;
  std::cout << "x >= 5 = " << (x >= 5) << std::endl;
  std::cout << "6 >= y = " << (6 <= y) << std::endl;
  
  std::cout << "x < 1.0 = " << (x < 1.0) << std::endl;
  std::cout << "2 > y = " << (2.0 > y) << std::endl;
  std::cout << "x == 0.75 = " << (x == 0.75) << std::endl;
  std::cout << "1.5 != y = " << (1.5 != y) << std::endl;
  std::cout << "x >= 5 = " << (x >= 5.0) << std::endl;
  std::cout << "6 >= y = " << (6.0 <= y) << std::endl;
  
  x += Rational(1, 4);
  std::cout << "x += 1/4 --> x = " << x << std::endl;
  x *= 2;
  std::cout << "x *= 2 --> x = " << x << std::endl;
  
  y += 1;
  std::cout << "y += 1 --> y = " << y << std::endl;
  
  std::cout << "y++ = " << y++ << std::endl;
  std::cout << "y = " << y << std::endl;
  std::cout << "--y = " << --y << std::endl;
}

