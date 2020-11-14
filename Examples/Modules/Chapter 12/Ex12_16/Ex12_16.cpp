// Implementing a destructor
import <iostream>;
import box;

int main()
{
  std::cout << "There are now " << Box::getObjectCount() << " Box objects." << std::endl;

  const Box box1 {2.0, 3.0, 4.0};     // An arbitrary box
  Box box2 {5.0};                     // A box that is a cube

  std::cout << "There are now " << Box::getObjectCount() << " Box objects." << std::endl;

  for (double d {} ; d < 3.0 ; ++d)
  {
    Box box {d, d + 1.0, d + 2.0};
    std::cout << "Box volume is " << box.volume() << std::endl;
  }

  std::cout << "There are now " << Box::getObjectCount() << " Box objects." << std::endl;

  auto pBox{ std::make_unique<Box>(1.5, 2.5, 3.5) };
  std::cout << "Box volume is " << pBox->volume() << std::endl;
  std::cout << "There are now " << pBox->getObjectCount() << " Box objects." << std::endl;
}
