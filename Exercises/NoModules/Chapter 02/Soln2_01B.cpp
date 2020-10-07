// Exercise 2-1. Convert inches to feet and inches
// The number of inches per foot is constant, 
// and should not be changed within the program,
// so we recognize this by declaring it as a const.
//
// This solution uses std::format().
//
// Note: we always output "feet" and "inches", 
// even if it concerns only 1 foot or 1 inch.
// In a later chapter you will learn about the conditional 
// statements and expressions that allow you to refine this.

#include <iostream>
#include <format>

int main()
{
  const int inches_per_foot { 12 };    // Initialize constant variable

  std::cout << "This program will convert inches to feet and inches." << std::endl;

  int inches {};
  std::cout << "Please enter a number of inches: ";
  std::cin >> inches;

  const int feet = inches / inches_per_foot;
  const int remaining_inches = inches % inches_per_foot;

  std::cout 
    << std::format("{} inches equals {} feet and {} inches.", inches, feet, remaining_inches) 
    << std::endl;
}