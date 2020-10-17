// Animal class and classes derived from Animal

#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <string_view>

class Animal
{
public:
  Animal(std::string_view name, int weight);    // Constructor

protected:
  void who() const;                 // Display name and weight

private:
  std::string m_name;                    // Name of the animal
  int m_weight;                        // Weight of the animal
};

class Lion : public Animal
{
public:
  // Define Lion constructor that calls base class constructor
  Lion(std::string_view name, int weight)  
	  : Animal{name, weight} {}

  // Create function in derived class that hides and explicitly 
  // invokes the protected function of the base class
  void who() { return Animal::who(); }
};

class Aardvark : public Animal
{
public:
  using Animal::Animal;   // Inherit constructor instead (preferred)
  using Animal::who;      // Use using to alter acccess specifier instead (preferred)
};

#endif