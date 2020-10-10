// Moving the implementation of functions from the module interface file 
// to a module implementation file.
import <string>;
import <iostream>;
import words;

int main()
{
  words::Words the_words;
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