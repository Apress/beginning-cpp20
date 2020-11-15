// Implementing a less-than operator
import <iostream>;
import <vector>;
import box;

int main()
{
  std::vector boxes {Box {2.0, 2.0, 3.0}, Box {1.0, 3.0, 2.0},
                     Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 3.0}};
  Box smallBox {boxes[0]};
  for (const auto& box : boxes)
  {
    if (box < smallBox) smallBox = box;
  }

  std::cout << "The smallest box has dimensions "
    << smallBox.getLength() << 'x'
    << smallBox.getWidth()  << 'x'
    << smallBox.getHeight() << std::endl;
}
