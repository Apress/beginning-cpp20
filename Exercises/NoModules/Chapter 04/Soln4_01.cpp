// Exercise 4-1 Testing whether two integer values are equal. 

#include <iostream>

int main()
{
  int value1 {};
  int value2 {};

  std::cout << "Please input two integers, separated by a space: ";
  std::cin >> value1 >> value2;
  std::cout << std::endl;

  if (value1 == value2)
    std::cout << "The values you entered are the same (two times " << value1 << ")." << std::endl;
  else 
    std::cout << "The values you entered are not the same (" << value1 << " != " << value2 << ")." << std::endl;
}