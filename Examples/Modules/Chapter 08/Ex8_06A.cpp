// Passing a two-dimensional array to a function (range-based for loop)
import <iostream>;
import <array>;	          // For std::size()

double yield(const double values[][4], size_t n);

int main()
{
  double beans[3][4]{ { 1.0,   2.0,   3.0,   4.0},
                        { 5.0,   6.0,   7.0,   8.0},
                        { 9.0,  10.0,  11.0,  12.0} };

  std::cout << "Yield = " << yield(beans, std::size(beans))
    << std::endl;
}

// Function to compute total yield
double yield(const double array[][4], size_t size)
{
  double sum{};
  for (size_t i{}; i < size; ++i)  // Loop through rows
  {
    for (double val : array[i])    // Loop through elements in a row
    {
      sum += val;
    }
  }
  return sum;
}

