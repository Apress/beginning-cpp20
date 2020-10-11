// Using the subscript operator
#include <iostream>
#include <memory>
#include <random>       // For random number generation
#include <functional>   // For std::bind()
#include "Truckload.h"

// See Chapter 12 for an explanation of this function
auto createUniformPseudoRandomNumberGenerator(double max)
{
  std::random_device seeder;        // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() };    // Efficient pseudo-random generator
  std::uniform_real_distribution distribution{ 1.0, max }; // Generate in [1, max) interval
  return std::bind(distribution, generator);           //... and in the darkness bind them!
}

int main()
{
  const double limit {99.0};    // Upper limit on Box dimensions
  auto random = createUniformPseudoRandomNumberGenerator(limit);

  Truckload load;
  const size_t boxCount {16};   // Number of Box object to be created

  // Create boxCount Box objects
  for (size_t i {}; i < boxCount; ++i)
    load.addBox(std::make_shared<Box>(random(), random(), random()));

  std::cout << "The boxes in the Truckload are:\n";
  std::cout << load;

  // Find the largest Box in the Truckload
  double maxVolume {};
  size_t maxIndex {};
  size_t i {};
  while (load[i])
  {
    if (load[i]->volume() > maxVolume)
    {
      maxIndex = i;
      maxVolume = load[i]->volume();
    }
    ++i;
  }

  std::cout << "\nThe largest box is: ";
  std::cout << *load[maxIndex] << std::endl;

  load.removeBox(load[maxIndex]);
  std::cout << "\nAfter deleting the largest box, the Truckload contains:\n";
  std::cout << load;
}
