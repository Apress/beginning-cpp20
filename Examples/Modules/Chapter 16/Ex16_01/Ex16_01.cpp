// Throwing and catching exceptions
import <iostream>;

int main()
{
  for (size_t i {}; i < 5; ++i)
  {
    try
    {
      if (i < 2)
        throw i;

      std::cout << "i not thrown - value is " << i << std::endl;

      if (i > 3)
        throw "Here is another!";

      std::cout << "End of the try block." << std::endl;
    }
    catch (size_t i)     // Catch exceptions of type size_t
    {
      std::cout << "i caught - value is " << i << std::endl;
    }
    catch (const char* message)    // Catch exceptions of type char*
    {
      std::cout << "message caught - value is \"" << message << '"' << std::endl;
    }

    std::cout << "End of the for loop body (after the catch blocks)"
              << " - i is " << i << std::endl;
  }
}
