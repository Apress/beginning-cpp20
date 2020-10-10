// Splitting a module in multiple submodules
import words;

import <string>;
import <iostream>;

int main()
{
  words::Words the_words;
  std::string text;                    // The string to be sorted
  const auto separators{" ,.!?\"\n"};  // Word delimiters

  // Read the string to be processed from the keyboard
  std::cout << "Enter a string terminated by *:" << std::endl;
  getline(std::cin, text, '*');

  words::utils::extract_words(the_words, text, separators);
  if (the_words.empty())
  {
    std::cout << "No words in text." << std::endl;
    return 0;
  }

  words::sorting::sort(the_words);         // Sort the words
  words::utils::show_words(the_words);   // Output the words
}