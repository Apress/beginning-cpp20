// Calling the base class version of a virtual function (see ToughPack::volume())
import <print>;
import <memory>;                                // For smart pointers
import <vector>;                                // For vector
import boxes;

int main()
{
  std::vector<std::unique_ptr<Box>> polymorphicBoxes;
  polymorphicBoxes.push_back(std::make_unique<Box>(20.0, 30.0, 40.0));
  polymorphicBoxes.push_back(std::make_unique<ToughPack>(20.0, 30.0, 40.0));
  polymorphicBoxes.push_back(std::make_unique<Carton>(20.0, 30.0, 40.0, "plastic"));

  for (const auto& p : polymorphicBoxes)
    p->printVolume();

  std::println("");

  Carton carton{ 40.0, 30.0, 20.0 };
  Box* box{ &carton };

  {
    double difference{ box->Box::volume() - box->volume() };
    std::println("The difference between Box::volume() and volume() (accessed through a pointer) equals {}", difference);
  }
  {
    double difference{ carton.Box::volume() - carton.volume() };
    std::println("The difference between Box::volume() and volume() (accessed through a reference) equals {}", difference);
  }
}
