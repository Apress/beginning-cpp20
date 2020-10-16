// Exercise 7-6 Finding words that begin with a given letter.
// If you wanted the words ordered by the first letter, you could sort the contents of letter first.
// You could also retain all the sets of words for each letter in a separate vector for each set;
// for this you could in other words use a std::vector<std::vector<std::string>>.
// Here, we opted to gather the words for one letter and print out the results 
// during one iteration in the same loop.

#include <iostream>
#include <format>
#include <cctype>
#include <string> 
#include <vector> 

int main()
{
  std::string text;                                            // The text to be searched
  std::string letters;
  std::cout << "Enter some text terminated by *:\n";
  std::getline(std::cin, text, '*');
  std::cout << "\nEnter the starting letters for the words you want to find: ";
  std::cin >> letters;

  const std::string separators {" ,;:.\"!?'\n"};               // Word delimiters
  std::vector<std::string> words;                              // Words found
  const size_t perline {5};                                    // Words output per line
  size_t count {};                                             // Number of words found
  for (auto ch : letters)
  {
    size_t start {text.find_first_not_of(separators)};         // First word start index
    size_t max_length {};                                      // Maximum word length
    while (start != std::string::npos)                         // Find the words
    {
      auto end{ text.find_first_of(separators, start + 1) };   // Find end of word
      if (end == std::string::npos)                            // Found a separator?
        end = text.length();                                   // No, so set to last + 1
      auto word{ text.substr(start, end - start) };            // Record the word
      if (std::toupper(word[0]) == std::toupper(ch))           // If it begins with the current letter...
      {
        words.push_back(word);                                 // ...save the word
        if (max_length < word.length()) max_length = word.length();
      }

      start = text.find_first_not_of(separators, end + 1);     // Find 1st character of next word
    }
    // List words for current letter
    std::cout << "\nWords beginning with '" << ch << "' are:\n";
    for (auto& word : words)
    {
      std::cout << std::format("{:<{}}", word, max_length + 2);
      if (++count % perline) continue;
      std::cout << std::endl;
    }
    std::cout << std::endl;
    words.clear();
    count = 0;
  }
}
