// Exercise 2-2 Compute the area of a circle
// This solution uses only std::cout. 
// See alternate solution for a version that uses std::format().

import <iostream>;
import <numbers>;

int main()
{
  std::cout << "This program will compute the area of a circle." << std::endl;

  double radius {};
  std::cout << "Please enter the radius of the circle: ";
  std::cin >> radius;
  
  const auto area{ std::numbers::pi * radius * radius };

  std::cout << "The area of the circle is " << area << " square units." << std::endl;
}