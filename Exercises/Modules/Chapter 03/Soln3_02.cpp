// Exercise 3-2. Calculating the number of boxes that can be stored on a shelf, without overhang. 
// We have to calculate how many boxes we can get into a row,
// and how many rows we can have, and then multiply these numbers together.
// The 'no overhang' problem is easily handled: casting from double to long 
// (using static_cast<>()) ensures that the fractional part of the double value
// is omitted, and only whole boxes are counted. 
// By including static_cast<>() in the code, we are effectively telling the
// compiler that we know what information will be lost in the cast.

import <iostream>;
import <print>;

int main() 
{
  const int inches_per_foot {12};

  double shelf_length {};
  double shelf_depth {};
  int box_size {};

  // Prompt the user for both the shelf and box dimensions
  std::print("Enter shelf length (feet): ");
  std::cin >> shelf_length;

  std::print("Enter shelf depth (feet): ");
  std::cin >> shelf_depth;

  std::print("Enter length of the side of a box (inches): ");
  std::cin >> box_size;

  // Calculating the number of whole boxes needed to fill the shelf
  // (the parentheses surrounding the multiplications are optional).
  const long boxes {static_cast<long>((shelf_length * inches_per_foot) / box_size) *
                                static_cast<long>((shelf_depth * inches_per_foot) / box_size)};

  /*
  Note: instead of the one long statement, 
  it may be more readable to split this computation over a few lines:

    const double shelf_length_inches = shelf_length * inches_per_foot;
    const double shelf_depth_inches = shelf_length * inches_per_foot;
    const long complete_boxes_length = static_cast<long>(shelf_length_inches / box_size);
    const long complete_boxes_depth = static_cast<long>(shelf_length_inches / box_size);
    const double boxes = complete_boxes_length * complete_boxes_depth;

  In another variation, you may also first convert the box's dimension to feet
  (don't forget to cast box_size and/or inches_per_foot to double first...
  can you tell what you would get otherwise?):

      const double box_size_feet = static_cast<double>(box_size) / inches_per_foot;
      const double boxes = static_cast<long>(shelf_length / box_size_feet)
                         * static_cast<long>(shelf_depth / box_size_feet);
  */

  // Display the number of boxes
  std::println("The number of boxes that can be contained in a single layer is {}", boxes);
}