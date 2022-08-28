// Calling base class constructors in a derived class constructor
import <print>;
import carton;       // For the Carton class

int main()
{
  // Create four Carton objects
  Carton carton1;                           std::println("");
  Carton carton2 {"White-lined chipboard"}; std::println("");
  Carton carton3 {4.0, 5.0, 6.0, "PET"};    std::println("");
  Carton carton4 {2.0, "Folding boxboard"}; std::println("");
 
  std::println("carton1 volume is {}", carton1.volume());
  std::println("carton2 volume is {}", carton2.volume());
  std::println("carton3 volume is {}", carton3.volume());
  std::println("carton4 volume is {}", carton4.volume());
}
