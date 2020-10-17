// Calculating primes using dynamic memory allocation
import <iostream>;
import <format>;

#include <cmath>       // For square root function (std::sqrt())

int main()
{
  size_t max {};       // Number of primes required

  std::cout << "How many primes would you like? ";
  std::cin >> max;          // Read number required

  if (max == 0) return 0;   // Zero primes: do nothing

  auto* primes {new unsigned[max]};  // Allocate memory for max primes

  size_t count {1};         // Count of primes found
  primes[0] = 2;            // Insert first seed prime

  unsigned trial {3};       // Initial candidate prime

  while (count < max)
  {
    bool isprime {true};    // Indicates when a prime is found

    const auto limit = static_cast<unsigned>(std::sqrt(trial));
    for (size_t i {}; primes[i] <= limit && isprime; ++i)
    {
      isprime = trial % primes[i] > 0;  // False for exact division
    }

    if (isprime)                // We got one...
      primes[count++] = trial;  // ...so save it in primes array

    trial += 2;                 // Next value for checking
  }

  // Output primes 10 to a line
  for (size_t i{}; i < max; ++i)
  {
    std::cout << std::format("{:10}", primes[i]);
    if ((i + 1) % 10 == 0)      // After every 10th prime...
      std::cout << std::endl;   // ...start a new line
  }
  std::cout << std::endl;

  delete[] primes;              // Free up memory...
  primes = nullptr;             // ... and reset the pointer
}
