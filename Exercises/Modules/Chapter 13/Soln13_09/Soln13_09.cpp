// Exercise 13-9
// Adding an assignment operator for Truckload
import <iostream>;
import <memory>;
import <random>;       // For random number generation
import <functional>;   // For std::bind()
import truckload;

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
  const double limit{ 99.0 };    // Upper limit on Box dimensions
  auto random{ createUniformPseudoRandomNumberGenerator(limit) };

  Truckload load;
  const size_t boxCount {20};               // Number of Box object to be created

  // Create boxCount Box objects
  for (size_t i {}; i < boxCount; ++i)
    load.addBox(std::make_shared<Box>(random(), random(), random()));

  std::cout << "The boxes in the Truckload are:\n";
  std::cout << load << std::endl;

  Truckload copied;
  copied = load;		// Use copy assignment
 
  std::cout << "The boxes in the copied Truckload are:\n";
  std::cout << copied;
}
