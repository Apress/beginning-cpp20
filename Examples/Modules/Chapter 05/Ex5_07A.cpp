// Generating multiplication tables using nested loops
// In this version an indefinite for loop is used, in combination with break statements.
#include <iostream>
#include <format>
#include <cctype>		// for std::tolower()

int main()
{
  size_t table {};              // Table size
  const size_t table_min {2};   // Minimum table size - at least up to the 2-times
  const size_t table_max {12};  // Maximum table size
  char reply {};                // Response to prompt

  const size_t max_tries{ 3 };   // Max. number of times a user can try entering a table size
  do
  {
    for (size_t count{ 1 }; ; ++count)  // Indefinite loop
    {
      std::cout <<
        std::format("What size table would you like ({} to {})? ", table_min, table_max);
      std::cin >> table; // Get the table size

      // Make sure table size is within the limits
      if (table >= table_min && table <= table_max)
      {
        break;      // Exit the input loop
      }
      else if (count < max_tries)
      {
        std::cout << "Invalid input - try again.\n";
      }
      else
      {
        std::cout << "Invalid table size entered - yet again!\nSorry, only "
          << max_tries << " allowed - program terminated." << std::endl;
        return 1;
      }
    }


    // Create the top line of the table
    std::cout << std::format("{:>6}", '|');
    for (size_t i {1}; i <= table; ++i)
    {
      std::cout << std::format(" {:3} |", i);
    }
    std::cout << std::endl;

    // Create the separator row
    for (size_t i {}; i <= table; ++i)
    {
      std::cout << "------";
    }
    std::cout << std::endl;

    for (size_t i {1}; i <= table; ++i)
    {    // Iterate over rows
      std::cout << std::format(" {:3} |", i);      // Start the row

      // Output the values in a row
      for (size_t j {1}; j <= table; ++j)
      {
        std::cout << std::format(" {:3} |", i*j);  // For each column
      }
      std::cout << std::endl;                      // End the row
    }

    // Check if another table is required
    std::cout << "\nDo you want another table (y or n)? ";
    std::cin >> reply;

  } while (std::tolower(reply) == 'y');
}
