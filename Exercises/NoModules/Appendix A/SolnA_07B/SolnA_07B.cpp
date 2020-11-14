// Exercise A-7   External variables (based on Exercise A-6)
#include <iostream>
#include "PrintThis.h"
#include "PrintThat.h"
#include "Print.h"

int main()
{
  print_this("All we have to decide is what to do ");
  print_that("with the time that is given to us.");
                                 // -- Gandalf the Grey

  std::cout << "\n(print() was called " << count << " times)";
}