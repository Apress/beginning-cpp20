// Exercise 3-2. Calculating the number of boxes that can be stored on a shelf, without overhang. 
// We have to calculate how many boxes we can get into a row,
// and how many rows we can have, and then multiply these numbers together.
// The 'no overhang' problem is easily handled: casting from double to long 
// (using static_cast<>()) ensures that the fractional part of the double value
// is omitted, and only whole boxes are counted. 
// By including static_cast<>() in the code, we are effectively telling the
// compiler that we know what information will be lost in the cast.

#include <iostream>

int main() 
{
  const int inches_per_foot {12};

  double shelf_length {};
  double shelf_depth {};
  int box_size {};

  // Prompt the user for both the shelf and box dimensions
  std::cout << "Enter shelf length (feet): ";
  std::cin >> shelf_length;

  std::cout << "Enter shelf depth (feet): ";
  std::cin >> shelf_depth;

  std::cout << "Enter length ofthe side of a box (inches): ";
  std::cin >> box_size;

  // Calculating the number of whole boxes needed to fill the shelf.
  long boxes {static_cast<long>((shelf_length * inches_per_foot) / box_size) *
                                static_cast<long>((shelf_depth * inches_per_foot) / box_size)};

  // Displaying the number of boxes
  std::cout << "The number of boxes that can be contained in a single layer is " << boxes << std::endl;
}