// Using the std::isupper() / islower() character classification functions
#include <iostream>
#include <cctype>

int main()
{
  char letter {};                      // Store input here
  std::cout << "Enter a letter: ";     // Prompt for the input
  std::cin >> letter;

  if (std::isupper(letter))
  {
    std::cout << "You entered an uppercase letter." << std::endl;
    return 0;
  }

  if (std::islower(letter))
  {
    std::cout << "You entered a lowercase letter." << std::endl;
    return 0;
  }

  std::cout << "You did not enter a letter." << std::endl;
}
