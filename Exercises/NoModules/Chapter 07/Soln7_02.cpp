// Exercise 7-2 Frequency of words in text.
#include <iostream>
#include <format>
#include <string> 
#include <vector>

int main()
{
  std::string text;                                          // The text to be searched
  std::cout << "Enter some text terminated by *:\n";
  std::getline(std::cin, text, '*');

  const std::string separators {" ,;:.\"!?'\n"};             // Word delimiters
  std::vector<std::string> words;                            // Words found
  std::vector<size_t> counts;                                // Words counts (same order as words)

  size_t start {text.find_first_not_of(separators)};         // First word start index
  while (start != std::string::npos)                         // Find the words
  {
    size_t end {text.find_first_of(separators, start + 1)};  // Find end of word
    if (end == std::string::npos)                            // Found a separator?
      end = text.length();                                   // No, so set to last + 1
    std::string word{ text.substr(start, end - start) };     // Record the word

    // Check for word already in vector
    bool is_in {false};                  // true when word has been found before
    for (int i {}; i < words.size(); ++i)
    {
      if (words[i] == word)
      {
        ++counts[i];
        is_in = true;
        break;
      }
    }
    if (!is_in)                          // If it's a new word...
    {
      words.push_back(word);             // ...store the word...
      counts.push_back(1);               // ...and record the count
    }
    start = text.find_first_not_of(separators, end + 1);  // Find 1st character of next word
  }

  // Find maximum word length
  size_t max_length {};
  for (auto& word : words)
    if (max_length < word.length()) max_length = word.length();

  std::cout << "Your string contains the following " << words.size() << " words and counts:\n";
  size_t count {};                       // Numbers of words output
  const size_t perline {3};              // Number per line
  for (size_t i {}; i < words.size(); ++i)
  {
    std::cout << std::format("{:<{}}{:>4}  ", words[i], max_length, counts[i]);
    if (!(++count % perline))
      std::cout << std::endl;
  }
  std::cout << std::endl;
}