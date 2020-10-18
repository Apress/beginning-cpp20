// Exercise 16-5
/* Somewhat artificial example to practice lists of different, 
 * related exception types (mind the order + catch-by-reference!)
 * and rethrowing (catch-by-reference + "throw;" !)
 */

#include <iostream>
#include <random>     // For random number generation
#include <functional> // For std::bind()
#include "CurveBall.h"
#include "DomainExceptions.h"

void askEvenNumber();           // Ask the user to provide an even number

int main()
{
  try
  {
    askEvenNumber();
  }
  catch (const CurveBall& /*caught*/)
  {
    std::cerr << "...hit it out of the park!" << std::endl;
  }
}

/* Helper functions for askEvenNumber() */
void throwCurveBallSometimes(); // Throw a CurveBall exception 25% of the time
int readEvenNumber();           // Reads an even number from std::cin and verifies the input 
                                // (throws upon failure)

// Option 1: use recursion
void askEvenNumber()
{
  try
  {
    std::cout << "Please enter an even number: ";
    readEvenNumber();
  }
  catch (const NotANumber& nan)
  {
    std::cerr << nan.what() << std::endl;
    return;
  }
  catch (const std::domain_error& domainException)
  {
    std::cerr << domainException.what() << std::endl;
    askEvenNumber();  // Recursive call
  }
  catch (const std::exception& exception)
  {
    std::cerr << exception.what() << std::endl;
    throw;
  }
}

/*
// Option 2: use a loop
void askEvenNumber()
{
  bool repeat{ false };
  do
  {
    try
    {
      std::cout << "Please enter an even number: ";
    }
    catch (const NotANumber& nan)
    {
      std::cerr << nan.what() << std::endl;
      return;
    }
    catch (const std::out_of_range& range)
    {
      std::cerr << range.what() << std::endl;
      repeat = true;
    }
    catch (const std::exception& exception)
    {
      std::cerr << exception.what() << std::endl;
      throw;
    }
  }
  while (repeat);
}
*/

int readEvenNumber()
{
  int number;
  std::cin >> number;
  if (std::cin.fail()) // Check whether the user has effectively entered a number
  {
    std::cin.clear();  // Reset the stream's failure state
    std::string line;  // Read the erroneous input and discard it
    std::getline(std::cin, line);
    throw NotANumber{line};
  }
  
  throwCurveBallSometimes();
  
  if (number < 0)
    throw NegativeNumber{number};
  if (number % 2)
    throw OddNumber{number};

  return number;
}

// See Soln16_01 for an explanation of this function
auto createUniformPseudoRandomBooleanGenerator(double probabilityOfTrue)
{
  std::random_device seeder;        // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() };    // Efficient pseudo-random generator
  std::bernoulli_distribution distribution{ probabilityOfTrue }; // The name says it all...
  return std::bind(distribution, generator);           //... and in the darkness bind them!
}

// Throw a CurveBall exception 25% of the time
void throwCurveBallSometimes()
{
  static auto random{ createUniformPseudoRandomBooleanGenerator(0.25) };
  if (random())
    throw CurveBall{};
}