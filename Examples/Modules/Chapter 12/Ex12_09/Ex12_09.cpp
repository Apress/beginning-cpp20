// Const objects and const member functions
import <iostream>;
import box;

int main()
{
  // v-- this const was added...
  const Box myBox {3.0, 4.0, 5.0};
  std::cout << "myBox dimensions are " << myBox.getLength()
            << " by " << myBox.getWidth()
            << " by " << myBox.getHeight() << std::endl;

  // Invoking mutators / setters is not possible on a const object:
  //myBox.setLength(-20.0);       // ignored!
  //myBox.setWidth(40.0);
  //myBox.setHeight(10.0);
  //std::cout << "myBox dimensions are now " << myBox.getLength()  // 3 (unchanged)
  //  << " by " << myBox.getWidth()                        // by 40
  //  << " by " << myBox.getHeight() << std::endl;         // by 10

  std::cout << "myBox's volume is " << myBox.volume() << std::endl;
}
