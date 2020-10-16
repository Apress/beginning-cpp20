// Exercise 2-8. Finding the largest of two integers without comparing them.
import <iostream>;

int main()
{
  unsigned a {};
  unsigned b {};

  std::cout << "Enter a positive integer: ";
  std::cin >> a;
  std::cout << "Enter another positive integer: ";
  std::cin >> b;

  // The trick is that, for integer values x and y, 
  // x / y equals zero if x < y.
  // So unless a and b are equal, either a/b or b/a is zero,
  // meaning in (x * (a/b) + y * (b/a)) one of both operands of + equals 0.
  // Once you have that, it's just a matter of working out the details.

  const unsigned larger {(a * (a / b) + b * (b / a)) / (a / b + b / a)};
  const unsigned smaller {(b * (a / b) + a * (b / a)) / (a / b + b / a)};
  std::cout << "The larger integer is " << larger << ".\n"
            << "The smaller integer is " << smaller << '.' << std::endl;
}