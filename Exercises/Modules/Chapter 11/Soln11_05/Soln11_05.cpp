// Splitting a module interface into partitions
import <string>;
import <iostream>;
import words;

int main()
{
  words::Words the_words;  /* Renamed to sidestep name clash with words namespace! */
  std::string text;                    // The string to be sorted
  const auto separators{" ,.!?\"\n"};  // Word delimiters

  // Read the string to be processed from the keyboard
  std::cout << "Enter a string terminated by *:" << std::endl;
  getline(std::cin, text, '*');

  words::extract_words(the_words, text, separators);
  if (the_words.empty())
  {
    std::cout << "No words in text." << std::endl;
    return 0;
  }

  words::sort(the_words);         // Sort the words
  words::show_words(the_words);   // Output the words
}