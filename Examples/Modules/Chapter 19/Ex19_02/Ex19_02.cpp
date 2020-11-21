// Exercising the use of function pointers as callback functions
import <iostream>;
import <string>;
import <vector>;
import optimum;

// Comparison function prototypes:
bool less(const int&, const int&);
template <typename T> bool greater(const T&, const T&);
bool longer(const std::string&, const std::string&);

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::cout << "Minimum element: " << *findOptimum(numbers, less) << std::endl;
  std::cout << "Maximum element: " << *findOptimum(numbers, greater<int>) << std::endl;

  std::vector<std::string> names{ "Moe", "Larry", "Shemp", "Curly", "Joe", "Curly Joe" };
  std::cout << "Alphabetically last name: "
            << *findOptimum(names, greater<std::string>) << std::endl;
  std::cout << "Longest name: " << *findOptimum(names, longer) << std::endl;
}

bool less(const int& one, const int& other) { return one < other; }

template <typename T>
bool greater(const T& one, const T& other) { return one > other; }

bool longer(const std::string& one, const std::string& other)
{
  return one.length() > other.length();
}
