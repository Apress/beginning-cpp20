// Demonstrating scope, lifetime, and global variables
import <print>;

long count1{999L};         // Global count1
double count2{3.14};       // Global count2
int count3;                // Global count3 - default initialization

int main()
{ /* Function scope starts here */
  int count1{10};          // Hides global count1
  int count3{50};          // Hides global count3
  std::println("Value of outer count1 = {}",  count1);
  std::println("Value of global count1 = {}", ::count1);
  std::println("Value of global count2 = {}", count2);

  { /* New block scope starts here... */
    int count1{20};        // This is a new variable that hides the outer count1
    int count2{30};        // This hides global count2
    std::println("\nValue of inner count1 = {}", count1);
    std::println("Value of global count1 = {}",  ::count1);
    std::println("Value of inner count2 = {}",   count2);
    std::println("Value of global count2 = {}",  ::count2);

    count1 = ::count1 + 3;   // This sets inner count1 to global count1+3
    ++::count1;              // This changes global count1
    std::println("\nValue of inner count1 = {}", count1);
    std::println("Value of global count1 = {}",  ::count1);
    count3 += count2;        // Increments outer count3 by inner count2

    int count4 {};
  } /* ...and ends here. */

// std::println("{}", count4);  // count4 does not exist in this scope!

  std::println("\nValue of outer count1 = {}",  count1);
  std::println("Value of outer count3 = {}",    count3);
  std::println("Value of global count3 = {}", ::count3);

  std::println("Value of global count2 = {}", count2);
} /* Function scope ends here */
