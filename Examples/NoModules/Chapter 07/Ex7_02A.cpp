// Accessing characters in a string
// (same as Ex7_02, except that this version uses the more convenient range-based for loop)
#include <iostream>
#include <string>
#include <cctype>		// for std::isalpha() and tolower()

int main()
{
  std::string text;                              // Stores the input
  std::cout << "Enter a line of text:\n";
  std::getline(std::cin, text);                  // Read a line including spaces

  unsigned vowels {};                            // Count of vowels
  unsigned consonants {};                        // Count of consonants
  for (const auto& ch : text)
  {
    if (std::isalpha(ch))                        // Check for a letter
	{
      switch (std::tolower(ch))                  // Convert to lowercase
      {
        case 'a': case 'e': case 'i': case 'o': case 'u':
          ++vowels;
          break;

        default:
          ++consonants;
          break;
      }
	}
  }

  std::cout << "Your input contained " 
            << vowels << " vowels and "
            << consonants << " consonants."
			<< std::endl;
}
