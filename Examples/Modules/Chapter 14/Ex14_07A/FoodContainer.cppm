export module food;

import <iostream>;
import <string>;
import <string_view>;

export class FoodContainer
{
public:
  FoodContainer() { std::cout << "FoodContainer() called.\n"; }

  FoodContainer(std::string_view name) : name {name}
  { std::cout << "FoodContainer(string_view) called.\n"; }

  FoodContainer(std::string_view name, double density, double volume)
    : name {name}, density {density}, volume {volume}
  { std::cout << "FoodContainer(string_view,double,double) called.\n"; }

  ~FoodContainer() { std::cout << "FoodContainer destructor" << std::endl; }

  double getWeight() const { return volume * density; }

protected:  // Protected to make initialization in CerealPack constructor work (book says private)
  std::string name {"cereal"};  // Food type
  double volume {};             // Cubic inches
  double density {0.03};        // Pounds per cubic inch
};

