// Classifying the letters in a C-style string
#include <iostream>
#include <cctype>

int main()
{
  const int max_length {100};   // Array size
  char text[max_length] {};     // Array to hold input string

  std::cout << "Enter a line of text:" << std::endl;

  // Read a line of characters including spaces
  std::cin.getline(text, max_length);
  std::cout << "You entered:\n" << text << std::endl;

  size_t vowels {};            // Count of vowels
  size_t consonants {};        // Count of consonants
  for (int i {}; text[i] != '\0'; i++)
  {
    if (std::isalpha(text[i]))         // If it is a letter...
    {
      switch (std::tolower(text[i]))
      {                                // ...check lowercase...
        case 'a': case 'e': case 'i': case 'o': case 'u':
          ++vowels;                    // ...it is a vowel
          break;

        default:
          ++consonants;                    // ...it is a consonant
      }
    }
  }
  std::cout << "Your input contained " << vowels << " vowels and "
            << consonants << " consonants." << std::endl;
}
