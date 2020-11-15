// Sorting strings using range-based sort()
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
  std::ranges::sort(names,
    [](const auto& left, const auto& right) {return left.length() < right.length(); });
  std::cout << "Names sorted by length:" << std::endl;
  for (const auto& name : names) std::cout << name << ", ";
  std::cout << std::endl;
}
