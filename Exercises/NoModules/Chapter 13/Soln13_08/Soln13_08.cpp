// Exercise 13-8
// Creating a simply pseudo-random number generator (PRNG) functor class.
// Ours is a very limited one that generates numbers between 0 and 100.
// Seeding and using it requires some type conversions,
// but other than that our PRNG functor acts as a drop-in replacement to the original one!
#include <iostream>
#include <format>
#include <vector>
#include <random>       // For random number generation
#include <functional>   // For std::bind()
#include "Box.h"
#include "PRNG.h"

int main()
{
  const double limit {99};       // Upper limit on Box dimensions

  std::random_device seeder;     // True random number generator to obtain a seed (slow)
  auto random{ PseudoRandomNumberGenerator{ static_cast<int>(seeder()) } };

  const size_t boxCount {20}; // Number of Box object to be created
  std::vector<Box> boxes;     // Vector of Box objects

  // Create 20 Box objects
  for (size_t i {}; i < boxCount; ++i)
    boxes.push_back(Box{ static_cast<double>(random()), static_cast<double>(random()), static_cast<double>(random()) });

  size_t first {};     // Index of first Box object of pair
  size_t second {1};   // Index of second Box object of pair
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

  Box sum{ 0, 0, 0 };            // Start from an empty Box
  for (const auto& box : boxes)  // And then add all randomly generated Box objects
    sum += box;

  std::cout << "The sum of " << boxCount << " random boxes is " << sum << std::endl;
}
