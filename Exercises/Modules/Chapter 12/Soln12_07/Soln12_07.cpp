// Create a doubly-linked list of Packages
import box.random;
import truckload;
import <iostream>;

/*
   To show reverse iteration, we've modified findSmallestBox() to iterate in reverse order
 */

SharedBox findLargestBox(const Truckload& truckload);
SharedBox findSmallestBox(const Truckload& truckload);

int main()
{
  Truckload load;  // Create an empty list

  // Add 12 random Box objects to the list
  const size_t boxCount{ 12 };
  for (size_t i{}; i < boxCount; ++i)
    load.addBox(randomSharedBox());

  std::cout << "The random truckload:\n";
  load.listBoxes();
  std::cout << std::endl;

  std::cout << "The same random truckload in reverse:\n";
  load.listBoxesReversed();
  std::cout << std::endl;

  std::cout << "The largest box (found using forward iteration) is ";
  findLargestBox(load)->listBox();
  std::cout << std::endl;

  std::cout << "The smallest box (found using reverse iteration) is ";
  findSmallestBox(load)->listBox();
  std::cout << std::endl;
}

SharedBox findLargestBox(const Truckload& truckload)
{
  auto iterator{ truckload.getIterator() };  // Type of iterator is Truckload::Iterator
  SharedBox largestBox{ iterator.getFirstBox() };

  SharedBox nextBox{ iterator.getNextBox() };
  while (nextBox)
  {
    if (nextBox->compare(*largestBox) > 0)
      largestBox = nextBox;
    nextBox = iterator.getNextBox();
  }

  return largestBox;
}

SharedBox findSmallestBox(const Truckload& truckload)
{
  auto iterator{ truckload.getIterator() };  // Type of iterator is Truckload::Iterator
  SharedBox smallestBox{ iterator.getLastBox() };

  SharedBox nextBox{ iterator.getPreviousBox() };
  while (nextBox)
  {
    if (nextBox->compare(*smallestBox) < 0)
      smallestBox = nextBox;
    nextBox = iterator.getPreviousBox();
  }

  return smallestBox;
}