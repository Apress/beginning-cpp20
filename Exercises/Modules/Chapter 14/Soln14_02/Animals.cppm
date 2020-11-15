// Animal class and classes derived from Animal

export module animals;

import <string>;
import <string_view>;
import <iostream>;

export class Animal
{
public:
  Animal(std::string_view name, int weight)     // Constructor
    : m_name{ name }, m_weight{ weight }
  {}

protected:
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

  // Create function in derived class that hides and explicitly 
  // invokes the protected function of the base class
  void who() { return Animal::who(); }
};

export class Aardvark : public Animal
{
public:
  using Animal::Animal;   // Inherit constructor instead (preferred)
  using Animal::who;      // Use using to alter acccess specifier instead (preferred)
};

