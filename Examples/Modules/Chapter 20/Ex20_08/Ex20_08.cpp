// Altering elements through a mutable iterator
import <iostream>;
import <vector>;
import box;      // From Ex11_04

int main()
{
  std::vector boxes{ Box{ 1.0, 2.0, 3.0 } };  // A vector containing 1 Box

  auto iter{ boxes.begin() };
  std::cout << iter->volume() << std::endl;        // 6 == 1.0 * 2.0 * 3.0
  
  *iter = Box{ 2.0, 3.0, 4.0 };
  std::cout << iter->volume() << std::endl;        // 24 == 2.0 * 3.0 * 4.0

  iter->setHeight(7.0);
  std::cout << iter->volume() << std::endl;        // 42 == 2.0 * 3.0 * 7.0
}
