// Using a lambda expression from inside a member function (see Finder.cpp)
import <iostream>;
import <vector>;
import optimum;
import finder;

int main()
{
  std::vector<double> numbers{ 91, 18, 92, 22, 13, 43 };

  int number_to_search_for {};
  std::cout << "Please enter a number: ";
  std::cin >> number_to_search_for;

  Finder finder;
  finder.setNumberToSearchFor(number_to_search_for);
  std::cout << "The number nearest to " << finder.getNumberToSearchFor() << " is "
            << *finder.findNearest(numbers) << std::endl;
}
