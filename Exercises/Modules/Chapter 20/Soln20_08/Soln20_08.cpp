// Exercise 20-8 Apply remove-erase idiom to remove duplicate elements
import <iostream>;
import <random>;     // For random number generation
import <functional>; // For std::bind() and std::ref()
import <algorithm>;
import <vector>;

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

  // Why not use an algorithm as well to generate the random numbers!!
  // (Note: technically generate() is allowed to copy a function object 
  //  as often as it wants. std::ref() ensures that the algorithm 
  //  at all times operates on a reference to our random-number generator)
  auto generator{ createUniformPseudoRandomNumberGenerator(0, 10'000) };
  std::ranges::generate(numbers, std::ref(generator));

  // Algorithm number two
  std::ranges::sort(numbers);

  // And number three; this time combined with the remove-erase idiom (or unique-erase, if you will)
  /* Option 1: iterator-based */
  numbers.erase(std::unique(begin(numbers), end(numbers)), end(numbers));
  /* Option 2: range-based (sadly requires two statements...) */
  //const auto [to_erase_begin, to_erase_end] { std::ranges::unique(numbers) };
  //numbers.erase(to_erase_begin, to_erase_end);

  std::cout << "Number of unique numbers: " << numbers.size() << std::endl;
}
