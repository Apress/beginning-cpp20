// Exercising a function object with a member variable
#include <iostream>
#include <format>
#include "Optimum.h"
#include "Nearer.h"

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };

  int number_to_search_for {};
  std::cout << "Please enter a number: ";
  std::cin >> number_to_search_for;

  std::cout << std::format("The number nearest to {} is {}", 
                  number_to_search_for, 
                  *findOptimum(numbers, Nearer{ number_to_search_for })) << std::endl;
}
