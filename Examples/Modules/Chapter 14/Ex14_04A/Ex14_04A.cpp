// Defaulting the default constructor in a derived class
// without a default constructor in the base class
// is equivalent to deleting the default constructor.
import <print>;
import box;                 // For the Box class
import carton;              // For the Carton class

/* Note: this example will fail to compile! */

int main()
{
  // Create three Carton objects
  Carton carton1;                           std::println("");
  Carton carton2 {4.0, 5.0, 6.0, "PET"};    std::println("");
  Carton carton3 {2.0, "Folding boxboard"}; std::println("");

  std::println("carton1 volume is {}", carton1.volume());
  std::println("carton2 volume is {}", carton2.volume());
  std::println("carton3 volume is {}", carton3.volume());
}
