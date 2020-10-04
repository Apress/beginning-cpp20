// Implicit conversions of reference parameters
#include <iostream>

void double_it(double& it)      { it *= 2; }
void print_it(const double& it) { std::cout << it << std::endl; }

int main()
{
  double d{123};
  double_it(d);
  print_it(d);

  int i{456};
  // double_it(i);        /* error, does not compile! */
  print_it(i);
}
