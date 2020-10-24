// Defining and using a namespace
import <iostream>;
import <numbers>;
import squaring;

int main()
{
  std::cout << "math::sqrt2 has the value " << math::sqrt2 << std::endl;
  std::cout << "This should be 0: " << (math::sqrt2 - std::numbers::sqrt2) << std::endl;
  std::cout << "This should be 2: " << math::square(math::sqrt2) << std::endl;
}
