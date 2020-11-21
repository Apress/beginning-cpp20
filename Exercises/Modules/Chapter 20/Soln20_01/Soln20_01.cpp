// Exercise 20-1 Rework the Truckload class using std::vector<>
import <iostream>;
import <memory>;
import truckload;
import box.random;

/*
  In this solution we preserved the interface of the nested Iterator class.
  An alternative, of course, would be to define Iterator as an alias 
  for std::vector<Box>::iterator, and introduce begin() and end() members.
  But then all code using the iterators would have to be updated as well.
*/

int main()
{
  const double dimLimit{ 99.0 };             // Upper limit on Box dimensions
  Truckload load;
  const size_t boxCount{ 20 };               // Number of Box object to be created

  // Create boxCount Box objects
  for (size_t i{}; i < boxCount; ++i)
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