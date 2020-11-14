// Defining class members in a module implementation file

import <iostream>;  // For use of std::cout, std::endl, etc.
import box;         // For use of the Box class

int main()
{
  Box myBox{ 6.0, 6.0, 18.5 }; // Create a box
  std::cout << "Volume of the first Box object is " << myBox.volume() << std::endl;
}