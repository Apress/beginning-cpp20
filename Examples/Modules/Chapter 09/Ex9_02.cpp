// Using std::string_view parameters
import <iostream>;
import <format>;
import <string>;
import <string_view>;
import <vector>;

using std::string;
using std::string_view;
using std::vector;

void find_words(vector<string>& words, string_view str, string_view separators);
void list_words(const vector<string>& words);

int main()
{
  std::string text;         // The string to be searched
  std::cout << "Enter some text terminated by *:\n";
  std::getline(std::cin, text, '*');

  const std::string separators{ " ,;:.\"!?'\n" };  // Word delimiters
  std::vector<std::string> words;                 // Words found

  find_words(words, text, separators);
  list_words(words);
}

void find_words(vector<string>& words, string_view text, string_view separators)
{
  size_t start{ text.find_first_not_of(separators) }; // First word start index

  while (start != string_view::npos)                          // Find the words
  {
    size_t end{ text.find_first_of(separators, start + 1) };  // Find end of word
    if (end == string_view::npos)                             // Found a separator?
      end = text.length();                              // No, so set to end of text

    words.push_back(std::string{ text.substr(start, end - start) }); // Store the word
// Or: words.emplace_back(text.substr(start, end - start));    // (in-place construction)
    start = text.find_first_not_of(separators, end + 1); // Find 1st character of next word
  }
}

void list_words(const vector<string>& words)
{
  std::cout << "Your string contains the following " << words.size() << " words:\n";
  size_t count{};                 // Number of outputted words
  for (const auto& word : words)
  {
    std::cout << std::format("{:>15}", word);
    if (!(++count % 5))
      std::cout << std::endl;
  }
  std::cout << std::endl;
}
