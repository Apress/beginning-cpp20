// Cerealpack.cppm - Class defining a carton of cereal
export module cereal;
import <iostream>;
import carton;
import food;

export class CerealPack : public Carton, public FoodContainer
{
public:
  CerealPack(double length, double width, double height, std::string_view cerealType)
    : Carton {length, width, height, "Chipboard"}, FoodContainer {cerealType}
  {
    std::cout << "CerealPack constructor" << std::endl;
    FoodContainer::volume = 0.9 * Carton::volume();   // Set food container's volume
  }

  ~CerealPack()
  {
    std::cout << "CerealPack destructor" << std::endl;
  }
};

