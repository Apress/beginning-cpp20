// Exercise 17-5 Exercising the LinkedList template class
// This program reverses the text that is entered
import linked_list;
import <string>;
import <string_view>;
import <iostream>;

int main()
{
  std::string text;                              // Stores input prose or poem
  std::cout << "\nEnter a poem or prose over one or more lines.\n"
            << "Terminate the input with #:\n";
  getline(std::cin, text, '#');

  LinkedList<std::string> words;                 // List to store words

  // Extract words and store in the list
  std::string_view separators{ " ,.\"?!;:\n" };  // Separators between words
  size_t start {};                               // Start of a word
  size_t end {};                                 // separator position after a word
  while (std::string::npos != (start = text.find_first_not_of(separators, start)))
  {
    end = text.find_first_of(separators, start+1);
    words.push_back(text.substr(start,end-start));
    start = end;
  }

  // List the words 5 to a line
  std::cout << "\nThe words are:\n\n";
  auto iterator{ words.front_iterator() };
  size_t count {};                               // Word counter
  const size_t perline {5};                      // Worde per line
  while (iterator.hasValue())
  {
    std::cout << iterator.value() << ' ';
    if (!(++count % perline))
      std::cout << std::endl;
    iterator.next();
  }
  std::cout << std::endl;

  // List the words in reverse order 5 to a line
  std::cout << "\nIn reverse order, the words are:\n\n";
  iterator = words.back_iterator();
  count = 0;
  while (iterator.hasValue())
  {
    std::cout << iterator.value() << ' ';
    if(!(++count % perline))
      std::cout << std::endl;
    iterator.previous();
  }
  std::cout << std::endl;
}