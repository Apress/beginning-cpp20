// Throwing and catching Curveballs
#include "Curveball.h"
#include <iostream>

#include <random>     // For random number generation
#include <functional> // For std::bind()

void throwCurveballSometimes();           // Suggested solution
void throwCurveballSometimesBernouilli(); // Alternate solution

int main() 
{
  size_t number {1000};                             // Number of loop iterations
  size_t exceptionCount {};                         // Count of exceptions thrown

  for (size_t i {}; i < number; ++i)
  {
    try
    {
      throwCurveballSometimes();
      // throwCurveballSometimesBernouilli();
    }
    catch (const Curveball&)
    {
      exceptionCount++;
    }
  }
  
  std::cout << "Curveball exception thrown " << exceptionCount << " times out of " << number << ".\n";
}

// See Chapter 12 for an explanation of this function principle.
auto createUniformPseudoRandomNumberGenerator(double min, double max)
{
  std::random_device seeder;          // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() };      // Efficient pseudo-random generator
  std::uniform_real_distribution distribution{ min, max }; // Generate in [min, max) interval
  return std::bind(distribution, generator);             //... and in the darkness bind them!
}

// Throw a Curveball exception 25% of the time
void throwCurveballSometimes()
{
  static auto random{ createUniformPseudoRandomNumberGenerator(0, 100) };
  if (random() < 25)
    throw Curveball{};
}

/*
 Alternate solution: instead of generating numbers in the interval [0,100)
 using a std::uniform_real_distribution, and comparing against 25,
 you could also generate Boolean values directly using a std::bernoulli_distribution
 (see https://en.cppreference.com/w/cpp/numeric/random/bernoulli_distribution;
  named after https://en.wikipedia.org/wiki/Bernoulli_distribution):
*/
auto createUniformPseudoRandomBooleanGenerator(double probabilityOfTrue)
{
  std::random_device seeder;        // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() };    // Efficient pseudo-random generator
  std::bernoulli_distribution distribution{ probabilityOfTrue }; // The name says it all...
  return std::bind(distribution, generator);           //... and in the darkness bind them!
}

// Throw a Curveball exception 25% of the time
void throwCurveballSometimesBernouilli()
{
  static auto random{ createUniformPseudoRandomBooleanGenerator(0.25) };
  if (random())
    throw Curveball{};
}