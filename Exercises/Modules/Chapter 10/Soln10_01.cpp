// Exercise 10-1.cpp
// Create a function template for my_clamp(), 
// a template that produces functions to clamp values to a given interval.
// Different variations are possible, but we opted for the same as in the Standard Library:
// namely one where all three arguments are of the same type, and passed by reference-to-const.
import <iostream>;
import <format>;
import <string>;

/*
  Caution: the actual std::clamp() function uses a different argument order.
  Where the exercise suggests:
    my_clamp(value, low, high)
  but for the Standard Library function the order is as follows:
    std::clamp(low, value, high)
  This solution does as instructed, but keep this in mind if ever using std::clamp()!
 */

template<typename T> 
const T& my_clamp(const T& value, const T& low, const T& high);    // Function template prototype

int main() 
{
  std::cout << "2.0 clamped to interval [1.5, 2.5] is " << my_clamp(2.0, 1.5, 2.5) << std::endl;
  std::cout << "5.0 clamped to interval [1.5, 2.5] is " << my_clamp(5.0, 1.5, 2.5) << std::endl;

  int big_int {17011983}, small_int {10}, negative_int {-123};
  std::cout 
    << std::format("{} clamped to the interval [{},{}] is {}", 
          negative_int, small_int, big_int, my_clamp(negative_int, small_int, big_int))
    << std::endl;

  // And now for a less useful example...
  std::string a_string {"A"}, z_string {"Z"};
  std::string shakespeare{"It is not in the stars to hold our destiny but in ourselves"};
  std::cout << "William Shakespeare's quote clamped to [A-Z] is: " 
            << my_clamp(shakespeare, a_string, z_string) << std::endl;
}

// Template for functions to clamp a value to a closed interval
template<typename T> 
const T& my_clamp(const T& value, const T& low, const T& high)
{
  if (value < low) return low;
  else if (value < high) return value;
  else return high;
}
