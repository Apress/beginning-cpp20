// Multiple case actions
#include <iostream>
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
      break;
    default:
      std::cout << "You entered a consonant." << std::endl;
      break;
    }
  }
  else
  {
    std::cout << "You did not enter a letter." << std::endl;
  }
}
