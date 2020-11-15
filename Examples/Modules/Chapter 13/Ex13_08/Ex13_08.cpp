// Overloading a unary "rotate" operator
import <iostream>;
import box;

int main()
{
  Box someBox{ 1, 2, 3 };
  std::cout << ~someBox << std::endl;
}
