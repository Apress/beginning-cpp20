// Exercise 15-1 Animals.cppm 
// Animal classes
export module animals;

import <string>;
import <string_view>;

export class Animal
{
public:
  Animal(std::string_view name, unsigned weight);// Constructor
  virtual ~Animal() = default;                   // Very important: a virtual destructor!
  virtual std::string who() const;               // Return string containing name and weight
  virtual std::string_view sound() const = 0;    // Return the sound of an animal

private:
  std::string m_name;                            // Name of the animal
  unsigned m_weight;                             // Weight of the animal
};

export class Sheep : public Animal
{
public:
  using Animal::Animal;                          // Inherit constructor
  std::string_view sound() const override;       // Return the sound of a sheep
};

export class Dog : public Animal
{
public:
  using Animal::Animal;                          // Inherit constructor
  std::string_view sound() const override;       // Return the sound of a dog
};

export class Cow : public Animal
{
public:
  using Animal::Animal;                          // Inherit constructor
  std::string_view sound() const override;       // Return the sound of a cow
};

