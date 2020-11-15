// Exercise 13-3
// Implementing the missing /, *=, +=, and /= operators for the Box class
import <iostream>;
import box;

int main()
{
  Box box {2, 3, 4};
  std::cout << "Box is " << box << std::endl;
  size_t n {3};
  box *= 3;
  std::cout << "After multiplying by " << n << " box is " << box << std::endl;
  box /= 3;
  std::cout << "After dividing by " << n << ", the box is again " << box << std::endl;
  
  Box newBox {2 * box};
  std::cout << "Twice " << box << " is " << newBox << std::endl;
  
  std::cout << "Half that is again " << (newBox / 2) << std::endl;
  
  std::cout << "Adding both boxes gives " << (box + newBox) << std::endl;
  
  box += newBox;
  
  std::cout << "The same can be obtained by usign += as well: " << box << std::endl;
}
