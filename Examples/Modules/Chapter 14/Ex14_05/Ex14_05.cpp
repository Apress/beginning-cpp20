// Inheriting constructors
#include <iostream>
#include "Carton.h"       // For the Carton class

int main()
{
  Carton cart;                                    // Calls inherited default constructor
  Carton cube { 4.0 };                                 // Calls inherited constructor
  Carton copy { cube };                                // Calls default copy constructor
  Carton carton {1.0, 2.0, 3.0};                       // Calls inherited constructor
  Carton cerealCarton (50.0, 30.0, 20.0, "Chipboard"); // Calls Carton class constructor
}
