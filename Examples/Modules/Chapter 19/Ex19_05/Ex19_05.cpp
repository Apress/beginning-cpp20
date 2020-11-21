// Exercising the use of stateless lambda expressions as callback functions
import <iostream>;
import <string>;
import <string_view>;
import <vector>;
import optimum;

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::cout << "Minimum element: "
            << *findOptimum(numbers, [](int x, int y) { return x < y; }) << std::endl;
  std::cout << "Maximum element: "
            << *findOptimum(numbers, [](int x, int y) { return x > y; }) << std::endl;

  // Define two anonymous comparison functions for strings:
  auto alpha{ [](std::string_view x, std::string_view y) { return x > y; } };
  auto longer{ [](std::string_view x, std::string_view y) { return x.length() > y.length(); } };

  std::vector<std::string> names{ "Moe", "Larry", "Shemp", "Curly", "Joe", "Curly Joe" };
  std::cout << "Alphabetically last name: " << *findOptimum(names, alpha) << std::endl;
  std::cout << "Longest name: " << *findOptimum(names, longer) << std::endl;
}
