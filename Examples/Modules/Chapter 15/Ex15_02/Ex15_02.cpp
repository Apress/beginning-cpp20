// Using virtual functions
import <print>;
import boxes;

int main()
{
  Box box {20.0, 30.0, 40.0};
  ToughPack hardcase {20.0, 30.0, 40.0};        // A derived box - same size
  Carton carton {20.0, 30.0, 40.0, "Plastic"};  // A different derived box

  box.printVolume();        // Volume of Box
  hardcase.printVolume();   // Volume of ToughPack
  carton.printVolume();     // Volume of Carton

  // Now using a base pointer...
  Box* base {&box};        // Points to type Box
  std::println("\nbox volume through base pointer is {}", base->volume());
  base->printVolume();

  base = &hardcase;        // Points to type ToughPack
  std::println("hardcase volume through base pointer is {}", base->volume());
  base->printVolume();

  base = &carton;          // Points to type Carton
  std::println("carton volume through base pointer is {}", base->volume());
  base->printVolume();
}
