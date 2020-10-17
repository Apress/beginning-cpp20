// Exercise 14-4 Working with Employee and Executive objects

#include <iostream>
#include <vector>
#include "Person.h"

int main()
{
  std::vector<Employee> employees
  {
    Employee{ 21, "Randy Marathon", Gender::male, 34567 },
    Employee{ 32, "Anna Pothecary", Gender::female, 34578 },
    Employee{ 46, "Peter Out", Gender::male, 34589 },
    Employee{ 37, "Sheila Rangeit", Gender::female, 34598 },
    Employee{ 65, "Jack Ittin", Gender::male, 34667 }
  };

  for (const auto& employee : employees)
    employee.who();

  std::cout << std::endl;

  // Note: explicitly specifying the type in front of every {...} 
  // in a vector's initializer list, like we did for Employees, 
  // is actually not required...
  std::vector<Executive> executives
  {
    { 44, "Irwin Pootlemeyer", Gender::other, 35567 },
    { 32, "Alexa Workwell", Gender::female, 35578 },
    { 42, "Steve Stove", Gender::male, 35589 },
    { 33, "Sue Neenuf", Gender::female, 35598 },
    { 29, "Melanie Clair", Gender::female, 35667 }
  };

  for (const auto& executive : executives)
  {
    executive.who();
    executive.Employee::who();  // Executive, I shall know thy age!
  }
}