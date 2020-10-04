// Searching within substrings
#include <iostream>
#include <string>

int main()
{
  std::string text;          // The string to be searched
  std::string word;          // Substring to be found
  std::cout << "Enter the string to be searched and press Enter:\n";
  std::getline(std::cin, text);

  std::cout << "Enter the string to be found and press Enter:\n";
  std::getline(std::cin, word);

  size_t count{};            // Count of substring occurrences
  size_t index{};            // String index
  while ((index = text.find(word, index)) != std::string::npos)
  {
    ++count;
    index += word.length();  // Advance by full word (discards overlapping occurrences)
  }

  std::cout << "Your text contained " << count << " occurrences of \""
            << word << "\"." << std::endl;
}
