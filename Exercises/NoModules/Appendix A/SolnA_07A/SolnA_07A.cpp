// Exercise A-7   External variables (based on Exercise A-5)
#include <iostream>
#include "PrintThis.h"
#include "PrintThat.h"

extern unsigned count;

int main()
{
  print_this("It is our choices that show what we truly are, ");
  print_that("far more than our abilities.");
                                          // -- Albus Dumbledore

  std::cout << "\n(print() was called " << count << " times)";
}