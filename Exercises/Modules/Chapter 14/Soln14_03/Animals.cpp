// Exercise 14-3 - Animals.cpp
// Implementations of the Animal class and classes derived from Animal
module animals;
import <iostream>;

// Identify the animal
void Animal::who() const
{
  std::cout << "My name is " << m_name << " and I weigh " << m_weight << "lbs." << std::endl;
}

// Identify the Lion
void Lion::who() const
{
  std::cout << "Rrroarrrr... I am a lion. ";
  Animal::who();                       // Call base function
}

// Identify the Aardvark
void Aardvark::who() const
{
  Animal::who();                       // Call base function
  std::cout << "Oh. And I'm an aardvark. " << std::endl;
}