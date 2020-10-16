// Sorting an array in ascending sequence - using a vector<T> container
#include <iostream>
#include <format>
#include <vector>

int main()
{
  std::vector<double> x;    // Stores data to be sorted

  while (true)
  {
    double input {};        // Temporary store for a value
    std::cout << "Enter a non-zero value, or 0 to end: ";
    std::cin >> input;
    if (input == 0)
      break;

    x.push_back(input);
  }

  if (x.empty())
  {
    std::cout << "Nothing to sort..." << std::endl;
    return 0;
  }

  std::cout << "Starting sort." << std::endl;

  while (true)
  {
    bool swapped{ false };   // Becomes true when not all values are in order
    for (size_t i {}; i < x.size() - 1; ++i)
    {
      if (x[i] > x[i + 1])   // Out of order so swap them
      {
        const auto temp{ x[i] };
        x[i] = x[i+1];
        x[i + 1] = temp;
        swapped = true;
      }
    }

    if (!swapped)   // If there were no swaps
      break;        // ...all values are in order...
  }                 // ...otherwise, go round again.

  std::cout << "Your data in ascending sequence:\n";
  const size_t perline {10};   // Number output per line
  size_t n {};                 // Number on current line
  for (size_t i {}; i < x.size(); ++i)
  {
    std::cout << std::format("{:8.1f}", x[i]);
    if (++n == perline)        // When perline have been written...
    {
      std::cout << std::endl;  // Start a new line and...
      n = 0;                   // ...reset count on this line
    }
  }
  std::cout << std::endl;
}
