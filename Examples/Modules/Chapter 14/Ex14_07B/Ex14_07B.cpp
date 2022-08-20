// Ex14_07B - Disambiguating ambiguous member through 
// using declarations in the derived class (CerealPack)
#include <print>
import cereal;          // For the CerealPack class

int main()
{
  CerealPack cornflakes{ 8.0, 3.0, 10.0, "Cornflakes" };

  std::println("cornflakes volume is {:.3}", cornflakes.volume());
  std::println("cornflakes weight is {:.3}", cornflakes.getWeight());
}