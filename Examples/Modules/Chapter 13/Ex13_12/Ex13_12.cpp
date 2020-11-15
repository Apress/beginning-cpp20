// Defining a copy assignment operator
import message;
import <iostream>;

int main()
{
  Message beware{ "Careful" };
  Message warning;
  
  warning = beware;    // Call assignment operator

  std::cout << "After assignment beware is: " << beware.getText() << std::endl;
  std::cout << "After assignment warning is: " << warning.getText() << std::endl;
}