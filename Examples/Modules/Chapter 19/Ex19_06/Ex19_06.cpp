// Using a default capture-by-value clause to access a local variable 
// from within the body of a lambda expression.
import <iostream>;
import <vector>;
import optimum;

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };

  int number_to_search_for {};
  std::cout << "Please enter a number: ";
  std::cin >> number_to_search_for;

  auto nearer { [=](int x, int y) {
    return std::abs(x - number_to_search_for) < std::abs(y - number_to_search_for);
  }};
  std::cout << "The number nearest to " << number_to_search_for << " is "
            << *findOptimum(numbers, nearer) << std::endl;

  //unsigned count{};
  //auto counter{ [&](int x, int y) { ++count; return x < y; } };
  //findOptimum(numbers, counter);
  //std::cout << "Number of comparisons: " << count;
}
