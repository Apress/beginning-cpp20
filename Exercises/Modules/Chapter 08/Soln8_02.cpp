// Exercise 8-2 Reversing the order of a string of characters. 
/******************************************************************
The reverse() function works with an argument of type string, or a
C-style string terminated with '\0'.
*******************************************************************/
import <iostream>;
import <string>;

std::string reverse(std::string str);

int main()
{
  std::string sentence;
  std::cout << "Enter a sequence of characters, then press 'Enter': " << std::endl;
  getline(std::cin, sentence);

  std::cout << "\nYour sequence in reverse order is:\n";
  std::cout << reverse(sentence) << std::endl;

  std::cout << "\nHere is a demonstration of reverse() working with a C-style string:\n";

  char stuff[] {"abcdefg"};                      // C-style string
  std::cout << "\nThe original string is: \"" << stuff << "\""
            << "\nReversed it becomes: \"" << reverse(stuff) << "\"" << std::endl;
}

// Reverse a string in place
// The code here is working with a copy of the argument
// so the original is not affected.
std::string reverse(std::string str)
{
  const size_t length {str.length()};
  for (size_t i {}; i < length / 2; ++i)
  {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
  return str;
}