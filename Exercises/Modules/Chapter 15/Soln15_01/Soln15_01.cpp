// Exercise 15-1 Exercising Zoo and Animal classes
#include "Zoo.h"
#include <random>     // For random number generation
#include <functional> // For std::bind()
#include <iostream>
#include <array>
#include <string_view>

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
  const size_t num_name_options{ 10 };
  using NameOptions = std::array<std::string_view, num_name_options>;

  const NameOptions dogNames {
    "Fido", "Rover"  , "Lassie" , "Lambikins",  "Poochy",
    "Spit", "Gnasher", "Samuel" , "Wellington", "Patch"
  };
  const NameOptions sheepNames {
    "Bozo",    "Killer", "Tasty", "Pete", "Chops",
    "Blackie", "Whitey", "Eric" , "Sean", "Shep"
  };
  const NameOptions cowNames {
    "Dolly", "Daisy",   "Shakey", "Amy",   "Dilly",
    "Dizzy", "Eleanor", "Zippy" , "Zappy", "Happy"
  };

  const unsigned minDogWt{ 1 };     // Minimum weight of a dog in pounds
  const unsigned maxDogWt{ 120 };   // Maximum weight of a dog in pounds
  const unsigned minSheepWt{ 80 };  // Minimum weight of a dog in pounds
  const unsigned maxSheepWt{ 150 }; // Maximum weight of a dog in pounds
  const unsigned minCowWt{ 800 };   // Minimum weight of a dog in pounds
  const unsigned maxCowWt{ 1500 };  // Maximum weight of a dog in pounds

  auto randomAnimalType { createUniformPseudoRandomNumberGenerator(0, 2) }; // 0, 1, or 2
  auto randomNameIndex  { createUniformPseudoRandomNumberGenerator(0, num_name_options - 1) };
  auto randomDogWeight  { createUniformPseudoRandomNumberGenerator(minDogWt, maxDogWt) };
  auto randomSheepWeight{ createUniformPseudoRandomNumberGenerator(minSheepWt, maxSheepWt) };
  auto randomCowWeight  { createUniformPseudoRandomNumberGenerator(minCowWt, maxCowWt) } ;

  std::vector<AnimalPtr> animals;   // Stores smart pointers to animals
  size_t numAnimals {};             // Number of animals to be created
  std::cout << "How many animals in the zoo? ";
  std::cin >> numAnimals;
  
  Zoo zoo;                  // Create an empty Zoo
  
  // Create random animals and add them to the Zoo
  for (size_t i {}; i < numAnimals; ++i)
  {
    switch (randomAnimalType())
    {
    case 0:                // Create a sheep
      zoo.addAnimal(std::make_shared<Sheep>(sheepNames[randomNameIndex()], randomSheepWeight()));
      break;
    case 1:                // Create a dog
      zoo.addAnimal(std::make_shared<Dog>(dogNames[randomNameIndex()], randomDogWeight()));
      break;
    case 2:                // Create a cow
      zoo.addAnimal(std::make_shared<Cow>(cowNames[randomNameIndex()], randomCowWeight()));
      break;
    }
  }
  
  zoo.showAnimals();                             // Display the animals
}