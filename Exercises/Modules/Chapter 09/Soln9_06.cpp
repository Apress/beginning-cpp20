// Exercise 9-6. Passing a vector to a fixed-size std::span<>
import <iostream>;
import <vector>;
import <span>;

double average10(std::span<const double, 10> data);        // Function prototype

int main()
{
  std::vector values { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
  // double values[]{ 1.0, 2.0, 3.0 };           // Only three values!!!
  std::cout << "Average = " 
    << average10(std::span<const double, 10>{ values.data(), values.size() }) << std::endl;
}

// Function to compute an average
double average10(std::span<const double, 10> data)
{
  double sum{};               // Accumulate total in here
  for (double val : data)
    sum += val;               // Sum array elements
  return sum / data.size();   // Return average
}