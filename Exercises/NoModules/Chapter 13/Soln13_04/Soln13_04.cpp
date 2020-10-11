// Exercise 13-4
// Adding support for equality operators that compare Boxes and volumes
#include <iostream>
#include "Box.h"

/*
  Because the C++20 compiler automatically rewrites != expression 
  in terms of == and/or even reverses the order of the operands,
  only one additional operator overload definition is required to make it all work.
*/

int main()
{
  Box box1{ 1, 2, 3 };
  Box box2{ 3, 2, 1 };
  Box box3{ 1, 2, 3 };

  // Try out all == and != operators (old and new, the latter in both directions)
  std::cout << "box1 and box2 are " << (box1 == box2 ? "" : "not ") << "equal\n";
  std::cout << "box1 and box3 are " << (box1 != box3 ? "not " : "") << "equal\n";
  std::cout << "box1 is " << (box1 == 6.0 ? "" : "not ") << "equal to 6.0\n";
  std::cout << "10.0 is " << (10 != box2 ? "not " : "") << "equal to box2\n";
}
