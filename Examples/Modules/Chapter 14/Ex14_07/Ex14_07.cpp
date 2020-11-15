// Ex14_07 - doesn't compile!
// Using multiple inheritance can lead to ambiguity if members with 
// the same name are inherited from different base classes.
import <iostream>;
import cereal;             // For the CerealPack class

int main()
{
  CerealPack cornflakes{ 8.0, 3.0, 10.0, "Cornflakes" };

  std::cout << "cornflakes volume is " << cornflakes.volume() << std::endl
            << "cornflakes weight is " << cornflakes.getWeight() << std::endl;
/*
  // Here is one way to make this work (see Ex14_07A and B for alternatives)
  std::cout << "cornflakes volume is " << cornflakes.Carton::volume() << std::endl
          << "cornflakes weight is " << cornflakes.FoodContainer::getWeight() 
          << std::endl;
*/
}