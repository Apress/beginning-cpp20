// Using exceptions to signal index-out-of-bounds errors.
#include <iostream>
#include <memory>
#include "Truckload.h"
#include "RandomBoxes.h"

int main()
{
  Truckload load;
  const size_t boxCount {20};               // Number of Box object to be created

  // Create boxCount Box objects
  for (size_t i {}; i < boxCount; ++i)
    load.addBox(randomSharedBox());

  try
  {
    std::cout << "The truckload contains the following boxes: " << std::endl;
    for (size_t i {}; i < 100; ++i)
    {
	    std::cout << *load[i] << std::endl;
    }
  }
  catch (const std::exception& caughtException)
  {
    std::cerr << "Oops: " << caughtException.what() << std::endl;
  }
}
