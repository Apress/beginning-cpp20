// Your first algorithms: std::min_element() and max_element(),
// this time using the range-based versions.
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>    // For std::abs()

int main()
{
  std::vector numbers{ 91, 18, 92, 22, 13, 43 };
  std::cout << "Minimum element: "
            << *std::ranges::min_element(numbers) << std::endl;
  std::cout << "Maximum element: "
            << *std::ranges::max_element(numbers) << std::endl;

  int number_to_search_for {};
  std::cout << "Please enter a number: ";
  std::cin >> number_to_search_for;

  auto nearer { [=](int x, int y) {
    return std::abs(x - number_to_search_for) < std::abs(y - number_to_search_for);
  }};

  std::cout << "The number nearest to " << number_to_search_for << " is "
            << *std::ranges::min_element(numbers, nearer) << std::endl;
  std::cout << "The number furthest from " << number_to_search_for << " is "
            << *std::ranges::max_element(numbers, nearer) << std::endl;

/*
  const auto [nearest, furthest]
    { std::ranges::minmax_element(numbers, nearer) };

  std::cout << "The number nearest to " << number_to_search_for << " is "
            << *nearest << std::endl;
  std::cout << "The number furthest from " << number_to_search_for << " is "
            << *furthest << std::endl;
*/
}
