// Implicit conversions reduce the number of operator functions
import <iostream>;
import integer;

int main() 
{
  const Integer i{1};
  const Integer j{2};
  const auto result = (i * 2 + 4 / j - 1) % j;
  std::cout << result.getValue() << std::endl;
}
