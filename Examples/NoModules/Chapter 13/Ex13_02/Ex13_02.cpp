// Using the overloaded 'less-than' operators for Box ojects
#include <iostream>
#include <vector>
#include <format>
#include "Box.h"

// Display box dimensions
void show(const Box& box)
{
  std::cout << std::format("Box {:g}x{:g}x{:g}", 
                 box.getLength(), box.getWidth(), box.getHeight()) << std::endl;
}

int main()
{
  std::vector boxes {Box {2.0, 2.0, 3.0}, Box {1.0, 3.0, 2.0},
                     Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 3.0}};
  const double minVolume{6.0};
  std::cout << "Objects with volumes less than " << minVolume << " are:\n";
  for (const auto& box : boxes)
    if (box < minVolume) show(box);

  std::cout << "Objects with volumes greater than " << minVolume << " are:\n";
  for (const auto& box : boxes)
    if (minVolume < box) show(box);
}
