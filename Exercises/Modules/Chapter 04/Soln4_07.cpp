// Exercise 4-7 Outputting the binary code for a letter.
/*
 * Most of the program is fairly simple. 
 * The cctype functions make determining upper or lower case easy. 
 * Finding out if it's a vowel is also easy with a switch.
 * Only getting the binary code needs a little thought, though. 
 * Each of the masks selects a different bit of the ch variable.
 * If the bit is '1', the expression will be non-zero, which is converted to Boolean true.
 * If it's '0', the whole expression will be zero, or Boolean false.
 * Ones and zeros are therefore output as appropriate.
 */
import <iostream>;

#include <cctype>

int main()
{
  char entered_letter {};
  std::cout << "Enter a letter: ";
  std::cin >> entered_letter;

  if (!std::isalpha(entered_letter)) 
  {
    std::cout << "That's not a letter!" << std::endl;
    return 1;
  }

  // We'll need the lower case letter...
  const auto lower_case_letter{ static_cast<char>(std::tolower(entered_letter)) };

  // Determine upper or lower case.
  std::cout << "'" << entered_letter << "' is " << 
    (std::islower(entered_letter) ? "lowercase" : "uppercase") << '.' << std::endl;

  // Determine whether it is a vowel or a consonant.
  std::cout << "'" << entered_letter << "' is a ";

  switch (lower_case_letter)
  {
    case 'a': case 'e': case 'i': case 'o': case 'u':
      std::cout << "vowel";
      break;
    default:
      std::cout << "consonant";
      break;
  }
  std::cout << '.' << std::endl;

  // Output the character code as binary
  std::cout << "The binary code for '" << lower_case_letter << "' is "
     << ((lower_case_letter & 0b10000000)? 1 : 0) 
     << ((lower_case_letter & 0b01000000)? 1 : 0)
     << ((lower_case_letter & 0b00100000)? 1 : 0) 
     << ((lower_case_letter & 0b00010000)? 1 : 0)
     << ((lower_case_letter & 0b00001000)? 1 : 0) 
     << ((lower_case_letter & 0b00000100)? 1 : 0)
     << ((lower_case_letter & 0b00000010)? 1 : 0) 
     << ((lower_case_letter & 0b00000001)? 1 : 0)
     << std::endl;

  return 0;
}