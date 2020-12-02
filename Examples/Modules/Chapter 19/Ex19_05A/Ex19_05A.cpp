// If possible, using the standard functors instead of lambda expressions 
// often leads to more compact and elegant code.
import <iostream>;
import <string>;
import <string_view>;
import <functional>;
import <vector>;
import optimum;

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::cout << "Minimum element: "
            << *findOptimum(numbers, std::less<>{}) << std::endl;
  std::cout << "Maximum element: "
            << *findOptimum(numbers, std::greater<>{}) << std::endl;

  // Define two anonymous comparison functions for strings:
  auto alpha{ std::greater<>{} };
  auto longer{ [](std::string_view x, std::string_view y) { return x.length() > y.length(); } };

  std::vector<std::string> names{ "Moe", "Larry", "Shemp", "Curly", "Joe", "Curly Joe" };
  std::cout << "Alphabetically last name: " << *findOptimum(names, alpha) << std::endl;
  std::cout << "Longest name: " << *findOptimum(names, longer) << std::endl;
}
