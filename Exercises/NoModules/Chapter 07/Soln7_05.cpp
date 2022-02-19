// Exercise 7-5 Check for anagrams, ignoring spaces.
// We chose to ignore all non-alphanumeric characters, not just spaces.
#include <iostream>
#include <cctype>
#include <string>

int main() 
{
  std::string word1, word2;

  std::cout << "Enter the first word or phrase: ";
  std::getline(std::cin, word1);
  std::cout << "Enter the second word or phrase: ";
  std::getline(std::cin, word2);

  std::string word2_copy {word2};                // Copy word2 - because we will delete characters
  
  bool anagrams{true};                           // Assume anagrams: becomes false if found otherwise
  
  // Loop over all the characters in word1
  for (char c : word1)
  {
    if (!std::isalnum(c)) continue;              // Ignore characters that aren't alphanumeric.
    
    bool found {false};                          // Becomes true if c is found
    // Loop over all the characters in word2 (we need the index now, so a range-based for loop won't do)
    for (size_t i {}; i < word2_copy.length(); ++i)
    {
      if (std::tolower(word2_copy[i]) == std::tolower(c)) 
      {
        word2_copy.erase(i, 1);                  // Character found so erase from word2
        found = true;
        break;                                   // Caution: do not use erase(i), because that erases the entire substring starting at index i!
      }
    }
    if (!found)
    {
      anagrams = false;
      break;
    }
  }
  
  // No alphanumeric characters are allowed to be left in word2_copy anymore at this point
  for (char c : word2_copy)
  {
    if (std::isalnum(c))
    {
      anagrams = false;
      break;
    }
  }

  std::cout << word1 << " and " << word2 << " are "
    << (anagrams? "" : "not ")
    << "anagrams of one another."
    << std::endl;
}