// Exercise 14-3 - Animals.cpp
// Implementations of the Animal class and classes derived from Animal
module animals;
import <print>;

// Identify the animal
void Animal::who() const
{
  std::println("My name is {} and I weigh {} lbs.", m_name, m_weight);
}

// Identify the Lion
void Lion::who() const
{
  std::print("Rrroarrrr... I am a lion. ");
  Animal::who();                       // Call base function
}

// Identify the Aardvark
void Aardvark::who() const
{
  Animal::who();                       // Call base function
  std::println("Oh. And I'm an aardvark.");
}