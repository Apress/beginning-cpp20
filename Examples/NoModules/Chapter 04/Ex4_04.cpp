// Using a nested if
#include <iostream>

int main()
{
  char letter {};                      // Store input here
  std::cout << "Enter a letter: ";     // Prompt for the input
  std::cin >> letter;

  if (letter >= 'A')
  {                                    // letter is 'A' or larger
    if (letter <= 'Z')
    {                                  // letter is 'Z' or smaller
      std::cout << "You entered an uppercase letter." << std::endl;
      return 0;
    }
  }

  if (letter >= 'a')                   // Test for 'a' or larger
    if (letter <= 'z')
    {                                  // letter is >= 'a' and <= 'z'
      std::cout << "You entered a lowercase letter." << std::endl;
      return 0;
    }
  std::cout << "You did not enter a letter." << std::endl;
}
