// Using the switch statement
#include <iostream>

int main()
{
  std::cout << "Your electronic recipe book is at your service.\n"
            << "You can choose from the following delicious dishes:\n"
            << "1. Boiled eggs\n"
            << "2. Fried eggs\n"
            << "3. Scrambled eggs\n"
            << "4. Coddled eggs\n\n"
            << "Enter your selection number: ";

  int choice {};  // Stores selection value
  std::cin >> choice;

  switch (choice)
  {
  case 1:
    std::cout << "Boil some eggs." << std::endl;
    break;
  case 2:
    std::cout << "Fry some eggs." << std::endl;
    break;
  case 3:
    std::cout << "Scramble some eggs." << std::endl;
    break;
  case 4:
    std::cout << "Coddle some eggs."  << std::endl;
    break;
  default:
    std::cout << "You entered a wrong number - try raw eggs." << std::endl;
  }
}
