// Exercise 13-5
// Implementing the obvious operators for the Box class 
// to allow it to be used, for instance, in if statements.
// A Box is "true" if and only if its volume is non-zero.
import <iostream>;
import box;

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
}
