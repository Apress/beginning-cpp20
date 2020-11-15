// Exercise 20-9 Parallel version of 20-8
import <iostream>;
import <random>;     // For random number generation
import <functional>; // For std::bind() and std::ref()
import <algorithm>;
import <vector>;
import <execution>;

// Creates a preudo-random number generator (PRNG) that generates unsigned integers 
// in a closed interval [min, max].
// Caution: unlike std::uniform_real_distribution (see Chapter 12), 
// uniform_int_distribution generates values in a *closed* interval.
auto createUniformPseudoRandomNumberGenerator(unsigned min, unsigned max)
{
  std::random_device seeder;     // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() }; // Efficient pseudo-random generator
  std::uniform_int_distribution distribution{ min, max };      // Generate in [min, max]
  return std::bind(distribution, generator);        //... and in the darkness bind them!
}

int main()
{
  const size_t num_numbers{ 25'000 };
  std::vector<int> numbers(num_numbers);

  /* Caution: a pseudo-random number generator cannot safely be accessed concurrently! */
  auto generator{ createUniformPseudoRandomNumberGenerator(0, 10'000) };
  std::ranges::generate(numbers, std::ref(generator));

  // Algorithm number two
  std::sort(std::execution::par, begin(numbers), end(numbers));

  // And number three; this time combined with the remove-erase idiom (or unique-erase, if you will)
  numbers.erase(std::unique(std::execution::par, begin(numbers), end(numbers)), end(numbers));

  std::cout << "Number of unique numbers: " << numbers.size() << std::endl;
}
