// Modifying the result of an overloaded subscript operator
import <iostream>;
import <memory>;
import <random>;       // For random number generation
import <functional>;   // For std::bind()
import truckload;

/*
  Caution: in the text, we suggest to add 
    
    static SharedBox nullBox{};
  
  to the Truckload class definition. This will not compile.
  In-class definitions of non-const static members are only allowed
  if you add the inline keyword, as we did in this solution.
  See Chapter 12 for more explanation,
  and for the alternative of defining the member out-of-class.
*/

// See Chapter 12 for an explanation of this function
auto createUniformPseudoRandomNumberGenerator(double max)
{
  std::random_device seeder;        // True random number generator to obtain a seed (slow)
  std::default_random_engine generator{ seeder() };    // Efficient pseudo-random generator
  std::uniform_real_distribution distribution{ 1.0, max }; // Generate in [1, max) interval
  return std::bind(distribution, generator);           //... and in the darkness bind them!
}

int main()
{
  const double limit {99.0};    // Upper limit on Box dimensions
  auto random = createUniformPseudoRandomNumberGenerator(limit);

  Truckload load;
  const size_t boxCount {16};   // Number of Box object to be created

  // Create boxCount Box objects
  for (size_t i {}; i < boxCount; ++i)
    load.addBox(std::make_shared<Box>(random(), random(), random()));

  std::cout << "The boxes in the Truckload are:\n";
  std::cout << load;

  // Find the largest Box in the Truckload
  double maxVolume {};
  size_t maxIndex {};
  size_t i {};
  while (load[i])
  {
    if (load[i]->volume() > maxVolume)
    {
      maxIndex = i;
      maxVolume = load[i]->volume();
    }
    ++i;
  }

  std::cout << "\nThe largest box is: ";
  std::cout << *load[maxIndex] << std::endl;

  load.removeBox(load[maxIndex]);
  std::cout << "\nAfter deleting the largest box, the Truckload contains:\n";
  std::cout << load;

  load[0] = load[1];        // Copy 2nd element to the 1st
  std::cout << "\nAfter copying the 2nd element to the 1st, the list contains:\n";
  std::cout << load;

  load[1] = std::make_shared<Box>(*load[2] + *load[3]);
  std::cout << "\nAfter making the 2nd element a pointer to the 3rd plus 4th,"
                                                          " the list contains:\n";
  std::cout << load;
}
