// Floating-point control in a for loop
import <format>;
import <iostream>;
import <numbers>;

int main()
{
  const size_t values_per_line {3}; // Outputs per line
  size_t values_current_line {};    // Number of outputs on current line
  for (double radius {0.2}; radius < 3.0 + 0.001; radius += 0.2)
  {
    const auto area{ std::numbers::pi * radius * radius };
    std::cout << std::format("radius = {:4.2f}, area = {:5.2f}; ", radius, area);
    if (++values_current_line == values_per_line)  // When enough values written...
    {
      std::cout << std::endl;    // ...start a new line...
      values_current_line = 0;   // ...and reset the line counter
    }
  }
  std::cout << std::endl;
}
