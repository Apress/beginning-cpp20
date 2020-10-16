// Exercise 4-8
// Dividing a cash amount into quarters, nickels, dimes and cents.

#include <iostream>

int main()
{
  // Declare the constants (amounts of cents)
  const unsigned quarter {25};
  const unsigned dime {10};
  const unsigned nickel {5};

  double amountInDollars {0.0};
  std::cout << std::endl << "Please enter a cash amount between 0 and 10 dollars: $";
  std::cin >> amountInDollars;
  
  if (amountInDollars >= 0.0 && amountInDollars <= 10.0)
  {
    // Multiply dollar amount by 100 ($1 = 100 cents)
    // We add 0.5 to compensate for errors in binary floating-point representation
    auto amountInCents {static_cast<unsigned>(amountInDollars * 100.0 + 0.5)};

    // Find the number of quarters
    const auto quarters {amountInCents / quarter};
    amountInCents %= quarter;               // Get the remainder

    // Find the number of dimes
    const auto dimes {amountInCents / dime};
    amountInCents %= dime;                  // Get the remainder

    // Find the number of nickels
    const auto nickels {amountInCents / nickel};
    amountInCents %= nickel;                // Get the remainder

    // Find the number of pennies
    const auto pennies {amountInCents};     // The remainder is already in pennies

    std::cout << std::endl 
         << "The dollar value $" << amountInDollars << " can be broken down into:"  << std::endl
         << quarters << " quarter" << (quarters == 1? "" : "s") << ',' << std::endl
         << dimes    << " dime"    << (dimes    == 1? "" : "s") << ',' << std::endl
         << nickels  << " nickel"  << (nickels  == 1? "" : "s") << ',' << std::endl
         << pennies  << " penn"    << (pennies  == 1? "y" : "ies") << '.' << std::endl;
  }
  else
  {
    std::cout << std::endl << "You did not enter a dollar amount between 0 and 10." << std::endl;
  }
}