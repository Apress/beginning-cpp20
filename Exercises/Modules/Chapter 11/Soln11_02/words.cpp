module words;

import <iostream>;
import <format>;

size_t max_word_length(const words::Words& words);

void words::extract_words(Words& words, const std::string& text, const std::string& separators)
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

/* Additional helpers for word::sort(Words&) */
void swap(words::Words& words, size_t first, size_t second)
{
  auto temp{ words[first] };
  words[first] = words[second];
  words[second] = temp;
}

void sort(words::Words& words, size_t start, size_t end);

// Sort strings in ascending sequence
void words::sort(Words& words)
{
  if (!words.empty())
    ::sort(words, 0, words.size() - 1);
}

void sort(words::Words& words, size_t start, size_t end)
{
  // start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;

  // Choose middle address to partition set
  swap(words, start, (start + end) / 2);     // Swap middle address with start

  // Check words against chosen word
  size_t current {start};
  for (size_t i {start + 1}; i <= end; i++)
  {
    if (*words[i] < *words[start])           // Is word less than chosen word?
      swap(words, ++current, i);             // Yes, so swap to the left
  }

  swap(words, start, current);               // Swap chosen and last swapped words

  if (current > start) sort(words, start, current - 1); // Sort left subset if exists
  if (end > current + 1) sort(words, current + 1, end); // Sort right subset if exists
}

size_t max_word_length(const words::Words& words)
{
  size_t max {};
  for (auto& pword : words)
    if (max < pword->length()) max = pword->length();
  return max;
}

void words::show_words(const Words& words)
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
