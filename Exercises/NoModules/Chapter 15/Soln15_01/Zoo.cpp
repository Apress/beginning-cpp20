// Implementations of the Zoo class that stores pointers to Animals
#include "Zoo.h"
#include "Animals.h"
#include <iostream>

// Constructor from a vector of animals
Zoo::Zoo(const std::vector<AnimalPtr>& animals) 
  : m_animals{ animals } 
{}

// Add an animal to the zoo
void Zoo::addAnimal(AnimalPtr animal)
{
  m_animals.push_back(animal);
}

// Output the animals and the sound they make
void Zoo::showAnimals() const
{
  for (const auto& animal : m_animals)
  {
    std::cout << animal->who() << ' ' << animal->sound() << std::endl;
  }
}
