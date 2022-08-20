export module food;

#include <print>
import <string>;
import <string_view>;

export class FoodContainer
{
public:
  FoodContainer() { std::println("FoodContainer() called."); }

  FoodContainer(std::string_view name) : name {name}
  { std::println("FoodContainer(string_view) called."); }

  FoodContainer(std::string_view name, double density, double volume)
    : name {name}, density {density}, volume {volume}
  { std::println("FoodContainer(string_view,double,double) called."); }

  ~FoodContainer() { std::println("FoodContainer destructor"); }

  double getWeight() const { return volume * density; }

protected:
  std::string name {"cereal"};  // Food type
  double volume {};             // Cubic inches
  double density {0.03};        // Pounds per cubic inch
};
