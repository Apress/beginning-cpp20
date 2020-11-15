// Exercise 13-6
// In canonical C++, you should only implement a single operator to allow 
// objects to be used in if statements, and in Boolean expressions in general:
// a conversion operator for type bool.
//
// This conversion operator, moreover, is normally qualified as explicit.
// This is far from obvious: despite the explicit qualifier,
// objects still implicitly convert to bool in, for instance, if statements.
// As illustrated at the bottom of main(), however, 
// simply assigning a Box to a variable of type bool indeed no longer works
// without an explicit type conversion (in most cases this is the desired behavior).
#include <iostream>
#include "Box.h"

void testBox(const Box& box)
{
  std::cout << "The box's volume is " << box.volume() << ".\n";
  if (box)
	  std::cout << "This volume is non-zero.";
  if (!box)
	  std::cout << "This volume is zero.";
  std::cout << std::endl;
}

int main()
{
  Box box1{2, 3, 4};
  std::cout << "box1 is " << box1 << std::endl;
  testBox(box1);
  
  std::cout << std::endl;;

  Box box2{0, 0, 0};
  std::cout << "box2 is " << box2 << std::endl;
  testBox(box2);  

  // bool b1{ box1 };    /* Does not compile! */
  bool b2{ static_cast<bool>(box2) };  // Needs an explicit type conversion
}

