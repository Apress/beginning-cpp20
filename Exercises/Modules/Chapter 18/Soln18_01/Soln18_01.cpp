// Exercise 18-1 Define move operators for the Truckload class
#include <iostream>
#include <memory>
#include "Truckload.h"
#include "RandomBoxes.h"

/*
  Things to watch out for:
    - use of copy-and-swap / move-and-swap function
    - noexcept move and swap members
    - dislodge the linked list from the moved load in the move constructor
*/

int main()
{
  const double dimLimit {99.0};             // Upper limit on Box dimensions
  Truckload load;
  const size_t boxCount {20};               // Number of Box object to be created

  // Create boxCount Box objects
  for (size_t i {}; i < boxCount; ++i)
    load.addBox(randomSharedBox());

  std::cout << "The boxes in the Truckload are:\n";
  std::cout << load << std::endl;

  Truckload moveConstructedLoad{ std::move(load) };

  std::cout << "The boxes in the move constructed Truckload are:\n";
  std::cout << moveConstructedLoad << std::endl;

  Truckload moveAssignedLoad;
  moveAssignedLoad = std::move(moveConstructedLoad);
  
  std::cout << "The boxes in the move assigned Truckload are:\n";
  std::cout << moveAssignedLoad << std::endl;
}
