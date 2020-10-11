// Using the addition operator for Box objects
#include <iostream>
#include <format>
#include <vector>
#include <random>       // For random number generation
#include <functional>   // For std::bind()
#include "Box.h"

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
  const double limit {99};       // Upper limit on Box dimensions
  auto random { createUniformPseudoRandomNumberGenerator(limit) };

  const size_t boxCount {20}; // Number of Box object to be created
  std::vector<Box> boxes;     // Vector of Box objects

  // Create 20 Box objects
  for (size_t i {}; i < boxCount; ++i)
    boxes.push_back(Box{ random(), random(), random() });

  size_t first {};            // Index of first Box object of pair
  size_t second {1};          // Index of second Box object of pair
  double minVolume {(boxes[first] + boxes[second]).volume()};

  for (size_t i {}; i < boxCount - 1; ++i)
  {  
    for (size_t j {i + 1}; j < boxCount; j++)
    {
      if (boxes[i] + boxes[j] < minVolume)
      {
        first = i;
        second = j;
        minVolume = (boxes[i] + boxes[j]).volume();
      }
    }
  }

  std::cout << "The two boxes that sum to the smallest volume are "
            << boxes[first] << " and " << boxes[second] << '\n';
  std::cout << std::format("The volume of the first box is {:.1f}\n",
                            boxes[first].volume());
  std::cout << std::format("The volume of the second box is {:.1f}\n",
                            boxes[second].volume());
  std::cout << "The sum of these boxes is " << (boxes[first] + boxes[second]) << '\n';
  std::cout << std::format("The volume of the sum is {:.1f}", minVolume) << std::endl;
}
