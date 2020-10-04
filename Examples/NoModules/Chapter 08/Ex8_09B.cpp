// Passing an array to a function - pass by reference improved
#include <iostream>
#include <array>          // for std::size()

double average10(const double (&)[10]);        // Function prototype

int main()
{
  double values[] { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
 // double values[] { 1.0, 2.0, 3.0 };           // Only three values!!!
  std::cout << "Average = " << average10(values) << std::endl;
}

// Function to compute an average
double average10(const double (&array)[10])
{
  double sum {};                       // Accumulate total in here
  for (double val : array)
    sum += val;                        // Sum array elements
  return sum / std::size(array);       // Return average
}