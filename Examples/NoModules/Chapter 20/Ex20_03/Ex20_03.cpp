// Working with sets
#include <iostream>
#include <set>            // For the std::set<> container template

void printSet(const std::set<int>& my_set);  // Print the contents of a set to std::cout

int main()
{
  std::set<int> my_set;

  // Insert elements 1 through 4 in arbitrary order:
  my_set.insert(1);
  my_set.insert(4);
  my_set.insert(3);
  my_set.insert(3);  // Elements 3 and 1 are added twice
  my_set.insert(1);
  my_set.insert(2);

  printSet(my_set);

  std::cout << "The element 1 occurs " << my_set.count(1) << " time(s)" << std::endl;

  my_set.erase(1);   // Remove the element 1 once
  printSet(my_set);

  my_set.clear();    // Remove all elements
  printSet(my_set);
}

void printSet(const std::set<int>& my_set)
{
  std::cout << "There are " << my_set.size() << " elements in my_set: ";
  for (int element : my_set)       // A set, like all containers, is a range
    std::cout << element << ' ';
  std::cout << std::endl;
}
