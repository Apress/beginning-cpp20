// Remove Boxes from a Truckload without searching a second time
#include "RandomBoxes.h"
#include "Truckload.h"

/********************************************************************************\
  The key to the solution is that the Iterator object already contains
  a pointer to the Package that needs to be removed.
  Of course, external code cannot use a Package, but it can use the Iterator.
  To exploit the knowledge contained in the Iterator, we add an overload
  of the removeBox() function with an Iterator parameter instead of a Box.

  To facilitate things, we also added getCurrentBox() to Iterator,
  which allowed us to remove some duplicated code in the various other getters
  of that class.
  
  Both findLargestBox() and findSmallestBox() are updated to return an Iterator
  as well. Note that the same technique is used by all Standard Library 
  containers and algorithms (see Chapter 20)!

  Notice also that we created removePackage() to avoid duplicating this code
  in the two overloads of removeBox().

  An alternative solution that also does not duplicate the removal logic
  consists of using an Iterator in removeBox(SharedBox), 
  and then invoke removeBox(Iterator) once the box is found. 
  removePackage() is then no longer required. We recommend you give this a try!
\**********************************************************************************/

Truckload::Iterator findLargestBox(const Truckload& truckload);
Truckload::Iterator findSmallestBox(const Truckload& truckload);

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

  const auto largestIter{ findLargestBox(load) };
  const auto smallestIter{ findSmallestBox(load) };

  std::cout << "The largest box (found using forward iteration) is ";
  largestIter.getCurrentBox()->listBox();
  std::cout << '\n' << std::endl;

  load.removeBox(largestIter);

  std::cout << "The truckload without its largest box:\n";
  load.listBoxes();
  std::cout << std::endl;

  std::cout << "The smallest box (found using reverse iteration) is ";
  smallestIter.getCurrentBox()->listBox();
  std::cout << '\n' << std::endl;
  
  load.removeBox(smallestIter);

  std::cout << "The truckload without its smallest box (in reverse order):\n";
  load.listBoxesReversed();
}

Truckload::Iterator findLargestBox(const Truckload& truckload)
{
  auto iterator{ truckload.getIterator() };  // Type of iterator is Truckload::Iterator
  iterator.getFirstBox();
  auto largestBoxIterator{ iterator };

  while (iterator.getNextBox())
  {
    if (iterator.getCurrentBox()->compare(*largestBoxIterator.getCurrentBox()) > 0)
    {
      largestBoxIterator = iterator;
    }
  }

  return largestBoxIterator;
}

Truckload::Iterator findSmallestBox(const Truckload& truckload)
{
  auto iterator{ truckload.getIterator() };  // Type of iterator is Truckload::Iterator
  iterator.getLastBox();
  auto smallestBoxIterator{ iterator };

  while (iterator.getPreviousBox())
  {
    if (iterator.getCurrentBox()->compare(*smallestBoxIterator.getCurrentBox()) < 0)
    {
      smallestBoxIterator = iterator;
    }
  }

  return smallestBoxIterator;
}