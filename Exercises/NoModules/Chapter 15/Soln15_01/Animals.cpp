// Implementations of the Animal class and classes derived from Animal

#include "Animals.h"

// Constructor
Animal::Animal(std::string_view name, unsigned weight) 
  : m_name{ name }, m_weight{ weight }
{}

// Return string describing the animal
std::string Animal::who() const
{
  return "My name is " + m_name + ". My weight is " + std::to_string(m_weight) + " lbs.";
}

// Make like a sheep
std::string_view Sheep::sound() const
{
  return "Baaaa!!";
}

// Make like a dog
std::string_view Dog::sound() const
{
  return "Woof woof!!";
}

// Make like a cow
std::string_view Cow::sound() const
{
  return "Mooooo!!";
}