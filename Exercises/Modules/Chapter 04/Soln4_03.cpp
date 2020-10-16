// Exercise 4-3 Using nested ifs and a logical && to check the value of a number.

import <iostream>;

int main()
{
  double value {};

  std::cout << "Please enter a number between 1 and 100: ";
  std::cin >> value;
  std::cout << std::endl;

  if (value >= 1 && value <= 100)
  {
    std::cout << "The number you entered is ";
    
    if (value > 50)
      std::cout << "greater than 50";
    else if (value < 50)
      std::cout << "less than 50" << std::endl;
    else
      std::cout << "50" << std::endl;
  
    std::cout << '.' << std::endl;
  }
  else
  {
    std::cout << "The number is not between 1 and 100." << std::endl;
  }
}