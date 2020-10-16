// Using the if-else statement
import <iostream>;

int main()
{
  long number {};      // Stores input
  std::cout << "Enter an integer less than 2 billion: ";
  std::cin >> number;

  if (number % 2) // Test remainder after division by 2
  { // Here if remainder is 1
    std::cout << "Your number is odd." << std::endl;
  }
  else
  { // Here if remainder is 0
    std::cout << "Your number is even." << std::endl;
  }
}
