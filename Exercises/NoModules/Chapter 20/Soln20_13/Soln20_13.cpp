// Exercise 20-13: more fun with algorithms and ranges
#include <iostream>
#include <format>
#include <map>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std::ranges::views;

// Type aliases
using Words = std::vector<std::string_view>;
using WordCounts = std::map<std::string_view, size_t>;

// Function prototypes
Words extractWords(std::string_view text, std::string_view separators = " ,.!?\"\n");
WordCounts countWords(const Words& words);
void showWordCounts(const WordCounts& wordCounts);

/*
  Below we list a number of possible solutions.
  We're sure there are plenty more variations possible...
 */

size_t maxWordLength(const WordCounts& wordCounts)
{
  // Filter out words that occur only once + transform to word lengths using lambda expression
  auto frequentWordLengths {
    wordCounts
      | filter([](const auto wordCount) { return wordCount.second >= 2; })
      | transform([](const auto wordCount) { return wordCount.first.length(); })
  };

  return std::ranges::empty(frequentWordLengths) ? 0 : *std::ranges::max_element(frequentWordLengths);
}

size_t maxWordLength_1(const WordCounts& wordCounts)
{
  // Filter out words that occur only once, transform twice in a row with member pointers.
  auto frequentWordLengths {
    wordCounts
      | filter([](const auto wordCount) { return wordCount.second >= 2; })
      | transform(&WordCounts::value_type::first)  // Or, without alias: transform(&std::pair<const std::string_view, size_t>::first)
      | transform(&std::string_view::length)
  };

  return std::ranges::empty(frequentWordLengths) ? 0 : *std::ranges::max_element(frequentWordLengths);
}

size_t maxWordLength_2(const WordCounts& wordCounts)
{
  // Filter out words that occur only once, transform to words, project to lengths.
  auto frequentWords {
    wordCounts
      | filter([](const auto wordCount) { return wordCount.second >= 2; })
      | transform([](const auto wordCount) { return wordCount.first; })
  };

  return std::ranges::empty(frequentWords) 
    ? 0 
    : (*std::ranges::max_element(frequentWords, std::less<>{}, &std::string_view::length)).length();
}

size_t maxWordLength_3(const WordCounts& wordCounts)
{
  // Filter out words that occur only once
  auto frequentWordCounts 
    { wordCounts | filter([](const auto wordCount) { return wordCount.second >= 2; }) };
  
  // Project to obtain the words (the first element of the pairs in the map), 
  // and compare their lengths using a lambda expression
  return std::ranges::empty(frequentWordCounts) 
    ? 0 
    : std::ranges::max_element(
        frequentWordCounts,
        [](auto word1, auto word2) { return word1.length() < word2.length(); },
        &WordCounts::value_type::first  // Or, without alias: std::pair<const std::string_view, size_t>::first
      )->first.size();
}


int main()
{
  std::string text;    // The string to count words in

  // Read a string from the keyboard
  std::cout << "Enter a string terminated by *:" << std::endl;
  getline(std::cin, text, '*');

  const Words words{ extractWords(text) };
  if (words.empty())
  {
    std::cout << "No words in text." << std::endl;
    return 0;
  }

  const WordCounts wordCounts{ countWords(words) };
  showWordCounts(wordCounts);
}

Words extractWords(std::string_view text, std::string_view separators)
{
  Words words;
  size_t start{ text.find_first_not_of(separators) };    // Start 1st word
  size_t end{};                                          // Index for the end of a word
                                                         
  while (start != std::string_view::npos)                
  {                                                      
    end = text.find_first_of(separators, start + 1);     // Find end separator
    if (end == std::string_view::npos)                   // End of text?
      end = text.length();                               // Yes, so set to last+1
    words.push_back(text.substr(start, end - start));    
    start = text.find_first_not_of(separators, end + 1); // Find next word
  }

  return words;
}

WordCounts countWords(const Words& words)
{
  WordCounts result;
  for (auto& word : words)
    ++result[word];
  return result;
}

void showWordCounts(const WordCounts& wordCounts)
{
  const size_t field_width{ maxWordLength(wordCounts) + 1};
  const size_t words_per_line{5};

  size_t words_in_line{};      // Number of words in the current line
  char previous_initial{};
  for (const auto& [word, count] : wordCounts)
  {
    if (count < 2) continue;   // Skip words that appear only once

    // Output newline when initial letter changes or after 5 per line
    if ( (previous_initial && word[0] != previous_initial)
          || words_in_line++ == words_per_line)
    {
      words_in_line = 0;
      std::cout << std::endl;
    }
    // Output "word (count)", where word has a dynamic field width
    std::cout << std::format("{:>{}} ({:2})", word, field_width, count); 
    previous_initial = word[0];
  }
  std::cout << std::endl;
}
