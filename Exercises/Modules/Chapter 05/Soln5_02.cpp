// Exercise 5-2 Summing integers and calculating the average
import <iostream>;
import <format>;

#include <cctype>

int main()
{
  unsigned int count {};
  long long total {};
  
  while (true)
  {
    std::cout << "Enter an integer: ";
    int n;
    std::cin >> n;
    total += n;
    ++count;

    char yesno {};
    std::cout << "Do you want to enter another (y/n)?";
    std::cin >> yesno;

    if (std::tolower(yesno) == 'n')
      break;
  }
  
  std::cout 
    << std::format("The total is {}. The average is {:.2f}.", 
                      total, static_cast<double>(total) / count) 
    << std::endl;
}