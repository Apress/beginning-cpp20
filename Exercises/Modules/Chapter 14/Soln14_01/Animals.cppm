// Animal class and classes derived from Animal
export module animals;

// Note: Animal, Lion, and Aardvark would typically be defined each in their own (sub)module.
// This example shows that this does not have to be the case; that is:
//  - file and module names do not have to match the name of a class; and
//  - multiple classes may be declared and defined in the same module

import <string>;
import <string_view>;
import <iostream>;

export class Animal
{
public:
  Animal(std::string_view name, int weight)     // Constructor
    : m_name{ name }, m_weight{ weight }
  {}
  
  void who() const                  // Display name and weight
  {
    std::cout << "My name is " << m_name << " and I weigh " << m_weight << "lbs." << std::endl;
  }

private:
  std::string m_name;                    // Name of the animal
  int m_weight;                        // Weight of the animal
};

export class Lion : public Animal
{
public:
  // Define Lion constructor that calls base class constructor
  Lion(std::string_view name, int weight)  
	  : Animal{name, weight} {}
};

export class Aardvark : public Animal
{
public:
  using Animal::Animal;  // Inherit constructor instead (preferred)
};

