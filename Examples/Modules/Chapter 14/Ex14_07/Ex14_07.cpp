// Ex14_07 - doesn't compile!
// Using multiple inheritance can lead to ambiguity if members with 
// the same name are inherited from different base classes.
#include <print>
import cereal;             // For the CerealPack class

int main()
{
  CerealPack cornflakes{ 8.0, 3.0, 10.0, "Cornflakes" };

  std::println("cornflakes volume is {:.3}", cornflakes.volume());
  std::println("cornflakes weight is {:.3}", cornflakes.getWeight());
/*
  // Here is one way to make this work (see Ex14_07A and B for alternatives)
  std::println("cornflakes volume is {}", cornflakes.Carton::volume());
  std::println("cornflakes weight is {:.3}", cornflakes.FoodContainer::getWeight());
*/
}