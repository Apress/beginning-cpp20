// Defining alternate names for a namespace
import <string>;
import <iostream>;
import words;

namespace wrds
{
  // A using directive us not a declaration, 
  // and can therefore not be exported from a module.
  // Namespace aliases are therefore the preferred over 
  // using directives inside a namespace...
  using namespace words;
}

int main()
{
  wrds::Words the_words;
  std::string text;                    // The string to be sorted
  const auto separators{" ,.!?\"\n"};  // Word delimiters

  // Read the string to be processed from the keyboard
  std::cout << "Enter a string terminated by *:" << std::endl;
  getline(std::cin, text, '*');

  w::extract_words(the_words, text, separators);
  if (the_words.empty())
  {
    std::cout << "No words in text." << std::endl;
    return 0;
  }

  wrds::sort(the_words);         // Sort the words
  w::show_words(the_words);   // Output the words
}