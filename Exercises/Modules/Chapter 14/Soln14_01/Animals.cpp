// Implementations of the Animal class and classes derived from Animal

#include <iostream>
#include "Animals.h"

// Constructor
Animal::Animal(std::string_view name, int weight) 
	: m_name{name}, m_weight{weight}
{}

// Identify the animal
void Animal::who() const
{
  std::cout << "My name is " << m_name << " and I weigh " << m_weight << "lbs." << std::endl;
}