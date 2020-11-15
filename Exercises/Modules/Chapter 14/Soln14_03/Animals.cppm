// Animal class and classes derived from Animal
export module animals;

import <string>;
import <string_view>;

export class Animal
{
public:
  Animal(std::string_view name, int weight)     // Constructor
      : m_name{ name }, m_weight{ weight }
  {}

  void who() const;                 // Display name and weight

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

  void who() const;           // Define Lion-specific function
};

export class Aardvark : public Animal
{
public:
  using Animal::Animal;                 // Inherit constructor
  
  void who() const;       // Define Aardvark-specific function
};

