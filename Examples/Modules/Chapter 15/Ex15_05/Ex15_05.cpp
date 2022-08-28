// Using a reference parameter to call virtual function
import <print>;
import boxes;

// Global function to display the volume of a box
void printVolume(const Box& box)
{
  std::println("Box usable volume is {}", box.volume());
}

int main()
{
  Box box {20.0, 30.0, 40.0};                  // A base box
  ToughPack hardcase {20.0, 30.0, 40.0};       // A derived box - same size
  Carton carton {20.0, 30.0, 40.0, "Plastic"}; // A different derived box

  printVolume(box);       // Display volume of base box
  printVolume(hardcase);  // Display volume of derived box
  printVolume(carton);    // Display volume of derived box
}
