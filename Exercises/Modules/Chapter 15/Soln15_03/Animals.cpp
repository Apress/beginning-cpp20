// Implementations of the Animal class and classes derived from Animal

module animals;

// Constructor
Animal::Animal(std::string_view name, unsigned weight) 
  : m_name{ name }, m_weight{ weight }
{}

// Return string describing the animal
std::string Animal::who() const
{
  return "My name is " + m_name + ". My weight is " + std::to_string(m_weight) + " lbs.";
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