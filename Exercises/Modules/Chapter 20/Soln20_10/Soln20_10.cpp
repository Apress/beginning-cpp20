// Exercise 20-10: exercising projection with range-based algorithms
import <iostream>;
import <string>;
import <vector>;
import <algorithm>;

int main()
{
  std::vector<std::string> names{"Frodo Baggins", "Gandalf the Gray", 
    "Aragon", "Samwise Gamgee", "Peregrin Took", "Meriadoc Brandybuck", 
    "Gimli", "Legolas Greenleaf", "Boromir"};

  // Sort the names lexicographically
  std::ranges::sort(names);
  std::cout << "Names sorted lexicographically:" << std::endl;
  for (const auto& name : names) std::cout << name << ", ";
  std::cout << std::endl << std::endl;  

  // Sort the names by length
  /* Option 1: projection using member function pointer */
  std::ranges::sort(names, std::less<>{}, &std::string::length);
  /* Option 2: projection using lambda expression */
//  std::ranges::sort(names, std::less<>{}, [](const auto& name) { return name.length(); });
  std::cout << "Names sorted by length:" << std::endl;
  for (const auto& name : names) std::cout << name << ", ";
  std::cout << std::endl;
}
