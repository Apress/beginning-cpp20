// Exercise 4-2 Testing for exact division of one integer by another.
//              We can use an if statement to check that the input is valid 
//              and we can use another to arrange the input as we need. 
//              Then we use an if-else to generate the appropriate output.

import <iostream>;

int main()
{
  int value1 {};
  int value2 {};

  std::cout << "Please input two positive integers, separated by a space: ";
  std::cin >> value1 >> value2;
  std::cout << std::endl;

  if (value1 <= 0 || value2 <= 0)  // Valid input?
  {
    std::cout << "Sorry - positive integers only." << std::endl;
    return 1;
  }

  // Ensure that value1 is not smaller than value2
  if (value1 < value2)
  {         
    const auto temp{ value1 };    // swap if necessary
    value1 = value2;
    value2 = temp;
  }

  if (value1 % value2 == 0)
    std::cout << value2 << " divides into " << value1 << " exactly. " << std::endl;
  else 
    std::cout << value1 << " is not exactly divisible by " << value2 << std::endl;
}