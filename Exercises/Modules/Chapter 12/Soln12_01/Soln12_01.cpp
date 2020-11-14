// Implementing an Integer class
#include "Integer.h"
#include <iostream>

int main() 
{
  std::cout << "Create i with the value 10." << std::endl;
  Integer i {10};
  i.show();
  std::cout << "Change value  of i to 15." << std::endl;
//  i.m_value = 15;	// Cannot assign directly to m_value
  i.setValue(15);
  i.show();
 
  std::cout << "Create j with a value that is 150 times that of i." << std::endl;
  const Integer j {150 * i.getValue()};
  j.show();
  std::cout << "Set value of j to ." << std::endl;
// j.setValue(5000);  // Cannot call setValue() on const object 
                      // (show() and getValue() work, though)

  std::cout << "Create k with the value 789." << std::endl;
  Integer k {789};
  k.show();
  std::cout << "Set value of k to sum of i and j values." << std::endl;
  k.setValue(i.getValue() + j.getValue());
  k.show();
}