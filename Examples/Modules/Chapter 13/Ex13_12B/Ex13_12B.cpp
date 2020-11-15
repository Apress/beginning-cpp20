// Sneak preview: use copy-and-swap for copy assignment operator
// (see Chapter 17 for details, including the noexcept keyword...)
// In short, you eliminate duplicating the logic of copying an object
// by expressing the copy assignment operator in terms of the copy constructor.
// Less duplication means less room for error, less maintenance overhead, etc.
// Note: this solution is hinted at in a Note in the text, but not explicitly named.
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