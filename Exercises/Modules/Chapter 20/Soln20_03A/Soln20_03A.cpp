// Exercise 20-3 Replacing custom container types with standard ones
/*
	The following replacements were made compared to Soln17_06.cpp:
		- SparseArray<LinkedList<T>> --> std::multimap<size_t, T>
	
	This means that compared to Soln20_03, we replaced std::map<Key, std::vector<Value>>
	with the more compact (and efficient) std::multimap<Key, Value>. 
  This data structure was less discussed in the main text (as it is less used in practice), 
  but is actually more appropriate here.

  At the bottom, there's two alternative loops: one close to the original one,
  and one that takes advantage of the fact that the keys in the multimap are sorted.
*/
import <vector>;
import <map>;
import <string>;
import <iostream>;
import <utility>;

#include <cctype>

int main()
{
  std::string text;                                // Stores input prose or poem
  std::cout << "Enter a poem or prose over one or more lines.\n"
    << "Terminate the input with #:\n";
  getline(std::cin, text, '#');

  std::multimap<char, std::string> words;
  const std::string_view letters{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

  // Extract words and store in the appropriate list
  // A list in the SparseArray is selected by the index in letters of the first letter in a word.
  const std::string_view separators{ " \n\t,.\"?!;:" }; // Separators between words
  size_t start{};                                 // Start of a word
  size_t end{};                                   // separator position after a word
  while (std::string::npos != (start = text.find_first_not_of(separators, start)))
  {
    end = text.find_first_of(separators, start + 1);
    const auto word{ text.substr(start, end - start) };
    const auto letter{ static_cast<char>(std::toupper(word[0])) };
    words.insert({ letter, word });
    start = end;
  }

  // List the words in order 5 to a line
  const size_t perline{ 5 };

  /* Option 1: use a loop similar to the original one */
  for (char letter : letters)
  {
    if (!words.contains(letter))
      continue;

    size_t count{};                               // Word counter
    // Retrieve the range of all words that begin with letter
    const auto [begin, end] { words.equal_range(letter) };
    for (auto iter{ begin }; iter != end; ++iter)
    {
      if (count++ % perline == 0 && count != 1)
        std::cout << std::endl;
      std::cout << iter->second << ' ';
      
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;

  /* Option 2: take advantage of the fact that the keys are already sorted in the multimap */
  size_t count{};          // Word counter
  char previous_letter{};
  for (const auto& [letter, word] : words)
  {
    // Add extra enter after each new letter (but not the first time)
    if (count && letter != previous_letter)
    {
      std::cout << std::endl;
      count = 0;
    }

    if (count++ % perline == 0 && count != 1)
      std::cout << std::endl;
    std::cout << word << ' ';

    previous_letter = letter;
  }

  std::cout << std::endl;
}