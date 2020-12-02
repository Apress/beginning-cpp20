// Exercising the use of standard functors
import <iostream>;
import <functional>;
import <vector>;
import optimum;

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::cout << "Minimum element: " << *findOptimum(numbers, std::less<>{}) << std::endl;
  std::cout << "Maximum element: " << *findOptimum(numbers, std::greater<>{}) << std::endl;
}
