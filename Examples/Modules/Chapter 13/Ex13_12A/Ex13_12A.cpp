// Always define both copy members together
// (see also 'Rule of Five' in Chapter 18!)
import message;
import <iostream>;

int main()
{
  Message beware{ "Careful" };
  Message warning;
  
  warning = beware;    // Call assignment operator

  Message caution{ warning };

  std::cout << "After assignment beware is: " << beware.getText() << std::endl;
  std::cout << "After assignment warning is: " << warning.getText() << std::endl;
  std::cout << "As a copy of warning, caution is: " << caution.getText() << std::endl;
}