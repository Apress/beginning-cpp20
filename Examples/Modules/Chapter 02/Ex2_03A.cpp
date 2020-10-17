// Expressions with mixed variables types
// (The difference with the original example 
//  is the type of fish_count and inches_per_foot)
import <iostream>;
import <numbers>;   // For the pi constant

#include <cmath>    // For the square root function

int main()
{
  // 2 square feet pond surface for every 6 inches of fish
  const double fish_factor { 2.0/0.5 };       // Area per unit length of fish
  const unsigned int inches_per_foot { 12 };  // <-- Used to be of type double

  unsigned int fish_count {};  // Number of fish (used to be of type double as well)
  double fish_length {};       // Average length of fish

  std::cout << "Enter the number of fish you want to keep: ";
  std::cin >> fish_count;
  std::cout << "Enter the average fish length in inches: ";
  std::cin >> fish_length;
  fish_length /= inches_per_foot;  // Convert to feet
  std::cout << '\n';

  // Calculate the required surface area
  const double pond_area {fish_count * fish_length * fish_factor};

  // Calculate the pond diameter from the area
  const double pond_diameter {2.0 * std::sqrt(pond_area / std::numbers::pi)};

  std::cout << "Pond diameter required for " << fish_count << " fish is "
            << pond_diameter << " feet.\n";
}
