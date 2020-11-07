// Exercise 19-3. Comparing two sorting algorithms

#include <iostream>
#include <format>
#include <cmath>         // For std::log2()
#include <random>        // For random number generation
#include <functional>    // For std::bind() and 
#include "Sort.h"

// Function to generate a random integer 1 to 100 (both inclusive)
// Caution: unlike uniform_real_distribution, uniform_int_distribution 
// generates numbers in a closed interval [min, max].
auto createUniformPseudoRandomNumberGenerator()
{
  std::random_device seeder;       // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() };   // Efficient pseudo-random generator
  std::uniform_int_distribution distribution{ 1u, 100u }; // Generate in [0, 100] interval
  return std::bind(distribution, generator);          //... and in the darkness bind them!
}

auto generateRandomNumbers(unsigned number)
{
  static auto random{ createUniformPseudoRandomNumberGenerator() };
  std::vector<unsigned> random_numbers;
  for (unsigned i{}; i < number; ++i)
    random_numbers.push_back(random());
  return random_numbers;
}

int main()
{  
  unsigned count {};
  const auto counting_less{ [&count](int x, int y) { ++count; return x < y; } };
  
  for (auto size : { 500u, 1'000u, 2'000u, 4'000u })
  {
    const auto numbers{ generateRandomNumbers(size) };
    
    count = 0;                 // Reset the count
    auto copy{ numbers };      // Ensure both sorrting algorithms work on exact same random sequence
    quicksort(copy, counting_less);
    const auto quicksort_count{ count };
    
    count = 0;                 // Repeat for bubble sort algorithm
    copy = numbers;
    bubbleSort(copy, counting_less);
    const auto bubbleSort_count{ count };
    
    std::cout 
      << std::format(
          "Number of comparisons for {} elements:\n"
          " - quicksort: {} (n*log(n): {})\n"
          " - bubble sort: {} (n*n: {})\n",
          size,
          quicksort_count, static_cast<unsigned>(size * std::log2(size)),
          bubbleSort_count, (size * size)
        ) 
     << std::endl;
  }
}