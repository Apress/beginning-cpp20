// Exercise 7-8. Testing whether something is a tautogram.
// This version uses a totally different technique (first splits the text into words), 
// and as a bonus ignores small words, and only requires 70% of the words to start with the same letter.
// With this looser definition of tautogram "The only verdict is vengeance; a vendetta, held as a votive not in vain.", 
// not entirely coincidentally, passes as a "near tautogram".

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main()
{
  // Ignore small words
  const size_t small_word_bound{ 3 };             // Set to 0 to not ignore small words at all
  const double near_tautology_ratio_bound{ 0.7 }; // Set to 1 to always require 100% of the words to begin with the same letter

  std::string text;      // The text to be checked
  std::cout << "Enter some text terminated by *:\n";
  std::getline(std::cin, text, '*');
  
  std::vector<std::string> words;
  for (size_t i {}; i < text.length(); )
  {
    // Skip spaces until we find the start of a word...
    while (i < text.length() && !std::isalpha(text[i])) ++i;

    const size_t start{ i };

    // Search for the end of the word...
    while (i < text.length() && std::isalpha(text[i])) ++i;

    if (i > start)
    {
      words.push_back(text.substr(start, i - start));
    }
  }

  // Only search for tautograms where words start with Latin letters A - Z
  size_t counts[26] {}; // All counts are initialized to 0
  size_t long_word_count{};

  for (auto& word : words)
  {
    if (word.length() > small_word_bound)
    {
      ++long_word_count;
      const auto start_letter{ std::toupper(word[0]) };
      if (start_letter >= 'A' && start_letter <= 'Z')
      {
        ++counts[start_letter - 'A'];
      }
    }
  }

  // Look for the most common start letter
  size_t most_common_index{ 0 };
  for (size_t i{ 1 }; i < std::size(counts); ++i)
  {
    if (counts[i] > counts[most_common_index])
    {
      most_common_index = i;
    }
  }

  const auto most_common_start_letter{ static_cast<char>('A' + most_common_index) };

  if (counts[most_common_index] == words.size())
  {
    std::cout << "The text that you entered is a true tautogram.\n";
    std::cout << "All words start with the letter " << most_common_start_letter << '.';
  }
  else if (static_cast<double>(counts[most_common_index]) / long_word_count >= near_tautology_ratio_bound)
  {
    std::cout << "It is a \"near tautogram\", though, as most longer words do start with the letter " << most_common_start_letter << '.';
  }
  else
  {
    std::cout << "The text that you entered is no tautogram. Not even close.\n";
  }
}
