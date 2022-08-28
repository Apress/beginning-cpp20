// Destructors in a class hierarchy
import <print>;
import carton;   // For the Carton class

int main()
{
  Carton carton;
  Carton candyCarton{50.0, 30.0, 20.0, "SBB"};	// Solid bleached board

  std::println("carton volume is {}", carton.volume());
  std::println("candyCarton volume is {}", candyCarton.volume());
}
