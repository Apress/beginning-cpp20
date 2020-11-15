// Overloading pre- and postfix inrement and decrement operators
import <iostream>;
import box;

int main()
{
  Box theBox{ 3.0, 1.0, 3.0 };

  std::cout << "Our test Box is " << theBox << std::endl;

  std::cout << "Postfix increment evaluates to the original object: "
    << theBox++ << std::endl;

  std::cout << "After postfix increment: " << theBox << std::endl;

  std::cout << "Prefix decrement evaluates to the decremented object: "
    << --theBox << std::endl;
  std::cout << "After prefix decrement: " << theBox << std::endl;
}

