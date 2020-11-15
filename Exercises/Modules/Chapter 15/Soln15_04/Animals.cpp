// Implementations of the Animal class and classes derived from Animal

/*
  Because the Animal::m_weight member currently represents the total weight of the animal
  (we kept this from previous versions of these classes),
  we need to update the Animal's (total) weight during Sheep::shear().
  
  In an alternate, arguably more elegant solution:
    - Animal::m_weight could reprent the "true" weight of the animal
    - Sheep::getWeight() could return Animal::getWeight() + m_wool_weight
    - Sheep::shear() could simply set m_wool_weight to 0
 */

module animals;

// Constructor
Animal::Animal(std::string_view name, unsigned weight) 
  : m_name{ name }, m_weight{ weight }
{}

// Return string describing the animal
std::string Animal::who() const
{
  return "My name is " + getName() + ". My weight is " + std::to_string(getWeight()) + " lbs.";
}

void Animal::setWeight(unsigned weight)
{
  m_weight = weight;
}

// Sheep constructors
Sheep::Sheep(std::string_view name, unsigned weight)
  : Sheep{name, weight, static_cast<unsigned>(0.1 * weight)}
{
}

Sheep::Sheep(std::string_view name, unsigned weight, unsigned wool)
  : Animal{name, weight}
  , m_wool_weight{wool}
{
}

// Override the behaviour of getName() for Sheep to prepend "Woolly "
std::string Sheep::getName() const
{
  return "Woolly " + Animal::getName();
}

// Override getWeight() to subtract the weight of their wool from weight.
unsigned Sheep::getWeight() const
{
  return Animal::getWeight() - m_wool_weight;
}

unsigned Sheep::shear()
{
  // Somewhat odd statement that updates the total weight (stored in the Animal subobject)
  // to the actual weight of the sheep (see Sheep::getWeight()). 
  // Of course, we do this *before* setting the wool's weight to 0.
  setWeight(getWeight());
  
  const unsigned wool_weight{ m_wool_weight };
  m_wool_weight = 0;
  return wool_weight;

  // Alternative: use std::exchange() (see Exercise 18-5)
  //return std::exchange(m_wool_weight, 0);
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

// Override the behaviour of who() for Cows to hide their weight
std::string Cow::who() const
{
  return "My name is " + getName() + ".";
}

// Make like a cow
std::string_view Cow::sound() const
{
  return "Mooooo!!";
}