// Exercise 2-2 Compute the area of a circle
// This solution uses std::format() 
// to control the precision used when outputting the result
// (we opted for 2 decimals after the decimal points).

import <iostream>;
import <numbers>;
import <format>;

int main()
{
  std::cout << "This program will compute the area of a circle." << std::endl;

  double radius {};
  std::cout << "Please enter the radius of the circle: ";
  std::cin >> radius;
  
  const auto area{ std::numbers::pi * radius * radius };

  std::cout << std::format("The area of the circle is {:.2f} square units.", area) << std::endl;
}