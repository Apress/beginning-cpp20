// Using an interface class and indirect base classes
import <print>;
import <vector>;                     // For the vector container
import boxes;
import vessel;
import can;

int main()
{
  Box box {40, 30, 20};
  Can can {10, 3};
  Carton carton {40, 30, 20, "Plastic"};
  ToughPack hardcase {40, 30, 20};

  std::vector<const Vessel*> vessels {&box, &can, &carton, &hardcase};

  for (const auto* vessel : vessels)
    std::println("Volume is {:.6}", vessel->volume());
}
