// Exercise 19-3. Comparing sorting algorithms

#include <iostream>
#include <format>
#include <cmath>         // For std::log2()
#include <random>        // For random number generation
#include <functional>    // For std::bind() and 
#include <algorithm>     // For std::ranges::sort() (bonus algorithm)
#include "Sort.h"

/*
  If you look carefully, you will notice that our implementation of quicksort
  deviates from the theoretical expectations. The larger the input size,
  the more it deviates (as shown by the ratios in our output).
  Better implementations of quicksort are no doubt possible:
  on random data an optimal quicksort algorithm should perform, on average,
  at a ratio 1.39 of the log-linear best case performance.
  But better algorithms exist as well. As a reference, we also compared with
  the Standard Library's sort() algorithm you'll learn about in Chapter 20.
  This algorithm should perform very close to the theoretical optimum.
*/

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
    const auto bubble_sort_count{ count };
    
    // Not requested, but it is interesting (see earlier) 
    // to also compare with the sorting algorithm of the C++ Standard Library 
    count = 0;                 // Repeat once more for std::ranges::sort()  (see Chapter 20)
    copy = numbers;
    std::ranges::sort(copy, counting_less);
    const auto std_sort_count{ count };

    const auto quick_sort_theory = static_cast<unsigned>(size * std::log2(size));
    const auto bubble_sort_theory = size * size;
    const auto std_sort_theory = static_cast<unsigned>(size * std::log2(size));

    std::cout 
      << std::format(
          "Number of comparisons for {} elements:\n"
          " - quicksort: {} (n*log(n): {}; ratio: {:.2})\n"
          " - bubble sort: {} (n*n: {}; ratio: {:.2})\n"
          " - Standard Library sort: {} (n*log(n): {}; ratio: {:.2})\n",
          size,
          quicksort_count, quick_sort_theory, static_cast<float>(quick_sort_theory) / quicksort_count,
          bubble_sort_count, bubble_sort_theory, static_cast<float>(bubble_sort_theory) / bubble_sort_count,
          std_sort_count, std_sort_theory, static_cast<float>(std_sort_theory) / std_sort_count
        ) 
     << std::endl;
  }
}