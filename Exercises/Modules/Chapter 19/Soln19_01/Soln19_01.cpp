// Exercise 19-1. 
// A lambda expression returning the number of vector elements that begin with a given letter.

#include <iostream>
#include <format>
#include <string>
#include <vector>

int main()
{
  std::vector<std::string> words{"apple", "pear", "plum", "orange", "peach", "grape", "greengage"};
  std::cout << "Words are:\n";
  for (const auto& word : words)
    std::cout << std::format("{:10}", word);
  std::cout << std::endl;

  const auto count {
    [&words](char letter)
    {
      size_t n {};
      for (auto& word : words)
        if (letter == word[0]) ++n;
      return n;
    }
  };
  
  char ch {'p'};
  std::cout << std::format("There are {} words that begin with {}.\n", count(ch), ch);
  ch = 'g';
  std::cout << std::format("There are {} words that begin with {}.\n", count(ch), ch);
}