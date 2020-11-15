// Throwing and catching CurveBalls and throwing TooManyExceptions
#include "CurveBall.h"
#include "TooManyExceptions.h"

import <iostream>;

import <random>;     // For random number generation
import <functional>; // For std::bind()

void throwCurveBallSometimes();

// This program will terminate abnormally when the TooManyExceptions exception is thrown.
int main()
{
  size_t number{ 1000 };             // Number of loop iterations
  size_t exceptionCount {};          // Count of exceptions thrown
  const size_t maxExceptions{ 10 };  // Maximum number of exceptions

  for (size_t i {}; i < number; ++i)
  {
    try
    {
      throwCurveBallSometimes();
    }
    catch(CurveBall& e)
    {
      std::cout << e.what() << std::endl;
    
      if (++exceptionCount > maxExceptions)
        throw TooManyExceptions{ maxExceptions };
    }
  }
}

// See Soln16_01 (to generate Booleans, a bernoulli_distribution is actually most appropriate)
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