// Comparing data values (output using std::format())
import <iostream>;
import <format>;

int main()
{
  char first {};      // Stores the first character
  char second {};     // Stores the second character

  std::cout << "Enter a character: ";
  std::cin >> first;

  std::cout << "Enter a second character: ";
  std::cin >> second;

  std::cout << std::format("The value of the expression {} < {} is {}\n",
                           first, second, first < second);
  std::cout << std::format("The value of the expression {} == {} is {}\n",
                           first, second, first == second);
}
