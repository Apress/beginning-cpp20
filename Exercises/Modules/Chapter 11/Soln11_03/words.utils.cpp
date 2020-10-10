module words.utils;

import <iostream>;
import <format>;

size_t max_word_length(const words::Words& words)
{
  size_t max{};
  for (auto& pword : words)
    if (max < pword->length()) max = pword->length();
  return max;
}

void words::utils::extract_words(Words& words, const std::string& text, const std::string& separators)
{
  size_t start {text.find_first_not_of(separators)}; // Start index of first word

  while (start != std::string::npos)
  {
    size_t end{ text.find_first_of(separators, start + 1) }; // Find end of a word
    if (end == std::string::npos)                    // Found a separator?
      end = text.length();                           // Yes, so set to end of text
    words.push_back(std::make_shared<std::string>(text.substr(start, end - start)));
    start = text.find_first_not_of(separators, end + 1); // Find start next word
  }
}

void words::utils::show_words(const Words& words)
{
  const size_t field_width {max_word_length(words) + 1};
  const size_t words_per_line {8};
  std::cout << std::format("{:{}}", *words[0], field_width); // Output first word

  size_t words_in_line {};         // Number of words in current line
  for (size_t i {1}; i < words.size(); ++i)
  { // Output newline when initial letter changes or after 8 per line
    if ((*words[i])[0] != (*words[i - 1])[0] || ++words_in_line == words_per_line)
    {
      words_in_line = 0;
      std::cout << std::endl;
    }
    std::cout << std::format("{:{}}", *words[i], field_width); // Output a word
  }
  std::cout << std::endl;
}
