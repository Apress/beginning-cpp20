// Implementations of the Zoo class that stores pointers to Animals
module zoo;
import animals;
import <iostream>;
import <string>;        // For operator<<
import <string_view>;   // For operator<<

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

// Collect all Sheep in the Zoo using dynamic cast (the recommended way)
std::vector<SheepPtr> Zoo::herd() const
{
  std::vector<SheepPtr> sheep;
  for (auto animal : m_animals)
  {
    auto casted{ std::dynamic_pointer_cast<Sheep>(animal) };
    if (casted)
    {
      sheep.push_back(casted);
    }
  }
  return sheep;
}
