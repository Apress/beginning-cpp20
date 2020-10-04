// Exercise 4-3 Outputting the binary code for a letter.
/*
 * Most of the program is fairly simple. 
 * The cctype functions make determining upper or lower case easy. 
 * Finding out if it's a vowel is also easy with a switch.
 * Only getting the binary code needs a little thought, though.                                                           * 
 * Each of the masks selects a different bit of the ch variable.
 * If the bit is '1', the expression will be non-zero, which is converted to Boolean true.
 * If it's '0', the whole expression will be zero, or Boolean false.
 * Ones and zeros are therefore output as appropriate.
 */
#include <iostream>
#include <cctype>

int main()
{
  char ch {};
  std::cout << "Enter a letter: ";
  std::cin >> ch;

  if (!std::isalpha(ch)) 
  {
    std::cout << "That's not a letter!" << std::endl;
    return 1;
  }

  // Determine upper or lower case.
  std::cout << "'" << ch << "' is " << 
    (std::islower(ch) ? "lowercase" : "uppercase") << '.' << std::endl;

  // Determine whether it is a vowel or a consonant.
  std::cout << "'" << ch << "' is a ";
  switch(std::tolower(ch))
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
  std::cout << "The binary code for '" << ch << "' is "
     << ((ch & 0b10000000)? 1 : 0) 
	   << ((ch & 0b01000000)? 1 : 0)
     << ((ch & 0b00100000)? 1 : 0) 
	   << ((ch & 0b00010000)? 1 : 0)
     << ((ch & 0b00001000)? 1 : 0) 
	   << ((ch & 0b00000100)? 1 : 0)
     << ((ch & 0b00000010)? 1 : 0) 
	   << ((ch & 0b00000001)? 1 : 0)
     << std::endl;

  return 0;
}