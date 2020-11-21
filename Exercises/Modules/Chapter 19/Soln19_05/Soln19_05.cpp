// Exercise 19-5. 
// Using callback functions to implement the so-called observer pattern,
// where a callback function is called whenever a certain event occurs 
// (in this case: when a Box is delivered).

import <iostream>;
import truckload;
import delivery_truck;
import box.random;

void logDelivary(SharedBox box)
{
  std::cout << "The box " << *box << " was delivered. On time, as always!" << std::endl;
}

int main()
{
  const size_t boxCount {20};               // Number of Box object to be created

  // Create boxCount Box objects
  Truckload load;
  for (size_t i {}; i < boxCount; ++i)
    load.addBox(randomSharedBox());

  DeliveryTruck truck{ load };  // Copy the load, because we still need it below. 
                                // Note that all Boxes are shared, so the they themselves are not copied.
  
  // Register two callback functions:
  truck.registerOnDelivered(logDelivary);
  
  unsigned count {};
  truck.registerOnDelivered([&count](SharedBox) { ++count; });
  
  // Deliver some boxes:
  for (size_t i : { 5u, 8u, 11u })
    truck.deliverBox(load[i]);

  std::cout << count << " boxes were delivered. On time, as always!" << std::endl;
}