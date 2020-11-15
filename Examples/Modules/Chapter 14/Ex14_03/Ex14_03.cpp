// Using a derived class copy constructor
import <iostream>;
import carton;

int main()
{
  // Declare and initialize a Carton object
  Carton carton{ 20.0, 30.0, 40.0, "Expanded polystyrene" };
  std::cout << std::endl;

  Carton cartonCopy{ carton };  // Use copy constructor
  std::cout << std::endl;

  std::cout << "Volume of carton is " << carton.volume() << std::endl
            << "Volume of cartonCopy is " << cartonCopy.volume() << std::endl;
}
