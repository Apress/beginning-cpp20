// Ex14_07A - Disambiguating ambiguous member inheritance through casting
import <print>;
import cereal;             // For the CerealPack class

int main()
{
  CerealPack cornflakes{ 8.0, 3.0, 10.0, "Cornflakes" };

  std::println("cornflakes volume is {:.3}", static_cast<Carton&>(cornflakes).volume());
  std::println("cornflakes weight is {:.3}",
      static_cast<FoodContainer&>(cornflakes).getWeight());

 /*
  // Alternate solution by explicitly qualifying the base class name (see also Ex14_07)
  std::println("cornflakes volume is {:.3}", cornflakes.Carton::volume());
  std::println("cornflakes weight is {:.3}", cornflakes.FoodContainer::getWeight());
*/
}