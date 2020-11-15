// Catching any exception
#include <iostream>
#include <typeinfo>         // For use of typeid()
#include "Troubles.h"

int main()
{
  for (int i {}; i < 7; ++i)
  {
    try
    {
      try
      {
        if (i == 3)
          throw Trouble{};
        else if (i == 5)
          throw MoreTrouble{};
        else if (i == 6)
          throw BigTrouble{};
      }
      catch (const BigTrouble& bt)
      {
        std::cout << "Oh dear, big trouble. Let's handle it here and now." << std::endl;
        // Do not rethrow...
      }
      catch (...)   // Catch any other exception
      {
        std::cout << "We caught something else! Let's rethrow it. " << std::endl;
        throw;      // Rethrow current exception
      }
    }
    catch (const Trouble& t)
    {
      std::cout << typeid(t).name() << " object caught in outer block: "
                << t.what() << std::endl;
    }
    std::cout << "End of the for loop (after the catch blocks) - i is " << i << std::endl;
  }
}
