// Using a return statement to exit a switch statement
import <iostream>;

#include <cctype>

int main()
{
  char letter {};
  std::cout << "Enter a letter: ";
  std::cin >> letter;

  if (std::isalpha(letter))
  {
    switch (std::tolower(letter))
    {
    case 'a': case 'e': case 'i': case 'o': case 'u':
      std::cout << "You entered a vowel." << std::endl;
      return 0;                               // Ends the program
    }

    // We did not exit main() in the above switch, so letter is not a vowel:
    std::cout << "You entered a consonant." << std::endl;
  }
  else
  {
    std::cout << "You did not enter a letter." << std::endl;
  }
}
