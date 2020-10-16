// Multiple calculations in a loop expression's third control expression
// by using the comma operator
import <iostream>;
import <format>;

int main() 
{
  unsigned int limit {};
  std::cout << "This program calculates n! and the sum of the integers "
            << "up to n for values 1 to limit.\n";
  std::cout << "What upper limit for n would you like? ";
  std::cin >> limit;

  // The format string for all rows of the table
  const auto table_format{ "{:>8} {:>8} {:>20}\n" };
  
  // Output column headings
  std::cout << std::format(table_format, "integer", "sum", "factorial"); 

  for (unsigned long long n {1}, sum {1}, factorial {1}; n <= limit; 
                                  ++n, sum += n, factorial *= n)
  {
    std::cout << std::format(table_format, n, sum, factorial);
  }
}
