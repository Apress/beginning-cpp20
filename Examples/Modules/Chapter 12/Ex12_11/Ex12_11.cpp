// Const objects and const member functions
import <iostream>;
import box;

int main()
{
  const Box myBox {3.0, 4.0, 5.0};
  std::cout << "myBox dimensions are " << myBox.getLength()
            << " by " << myBox.getWidth()
            << " by " << myBox.getHeight() << std::endl;

  myBox.printVolume();
  myBox.printVolume();
  myBox.printVolume();
}
