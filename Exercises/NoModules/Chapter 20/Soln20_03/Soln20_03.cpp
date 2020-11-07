// Exercise 20-3 Replacing custom container types with standard ones
/*
	The following replacements were made compared to Soln17_06.cpp:
		- LinkedList<T> --> std::vector<T> (not std::list<>, because vector<> should
			be your go-to container; there's rarely a good reason to use linked lists)
		- SparseArray<T> --> std::map<char, T> (no need to use a size_t as the key!)
	
  Notice how much more elegant inserting and retrieving values from the map is.
  All loops at the end of the solution can now also be replaced with elegant range-based for loops.

  At the bottom, there's two alternative loops: one close to the original one,
  and one even more elegant one that takes advantage of the fact that the keys 
  in the map are already sorted.

	Soln20_03A contains alternative solutions based on std::multimap<>
*/
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <utility>

int main()
{
  std::string text;                                // Stores input prose or poem
  std::cout << "Enter a poem or prose over one or more lines.\n"
            << "Terminate the input with #:\n";
  getline(std::cin, text, '#');

  std::map<char, std::vector<std::string>> lists;
  
  // Extract words and store in the appropriate list
  const std::string_view separators {" \n\t,.\"?!;:"}; // Separators between words
  size_t start {};                                 // Start of a word
  size_t end {};                                   // separator position after a word
  while (std::string::npos != (start = text.find_first_not_of(separators, start)))
  {
    end = text.find_first_of(separators, start+1);
    const auto word{ text.substr(start, end - start) };
    const auto letter{ static_cast<char>(std::toupper(word[0])) };
    lists[letter].push_back(word);
    start = end;
  }

  // List the words in order 5 to a line
  const size_t perline {5};
  
  /* Option 1: use a loop similar to the original one */
  const std::string_view letters{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
  for (char letter : letters)
  {
    if (!lists.contains(letter))
      continue;
  
    size_t count {};                               // Word counter
    for (const auto& word : lists[letter])
    {
      if (count++ % perline == 0 && count != 1)
        std::cout << std::endl;
      std::cout << word << ' ';
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;

  /* Option 2: take advantage of the fact that the keys are already sorted in the map */
  for (const auto& [letter, list] : lists)
  {
    size_t count{};                               // Word counter
    for (const auto& word : list)
    {
      if (count++ % perline == 0 && count != 1)
        std::cout << std::endl;
      std::cout << word << ' ';
    }
    std::cout << std::endl;
  }
}