// Separating declarations and definitions of functions
// declared in a namespace.
import <iostream>;
import math;

int main()
{
  const double values[]{ 10, 2, 1, 8, 3, 7, 4, 5, 6, 9 };
  std::cout << "Arithmetic mean: " << math::averages::arithmetic_mean(values) << std::endl;
  std::cout << "Geometric mean: " << math::averages::geometric_mean(values) << std::endl;
  std::cout << "Root mean square: " << math::averages::rms(values) << std::endl;
  std::cout << "Median: " << math::averages::median(values) << std::endl;
}
