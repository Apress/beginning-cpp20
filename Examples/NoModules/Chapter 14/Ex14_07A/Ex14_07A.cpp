// Ex14_07A - Disambiguating ambiguous member inheritance through casting
#include <iostream>
#include "CerealPack.h"             // For the CerealPack class

int main()
{
  CerealPack cornflakes{ 8.0, 3.0, 10.0, "Cornflakes" };

 std::cout << "cornflakes volume is " << static_cast<Carton&>(cornflakes).volume()
    << std::endl         
    << "cornflakes weight is " << static_cast<FoodContainer&>(cornflakes).getWeight()
    << std::endl;
 /*
  // Alternate solution by explicitly qualifying the base class name (see also Ex14_07)
  std::cout << "cornflakes volume is " << cornflakes.Carton::volume() << std::endl
          << "cornflakes weight is " << cornflakes.FoodContainer::getWeight() 
          << std::endl;
*/
}