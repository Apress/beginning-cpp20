// Using a class template with a non-type parameter
import box;
import array;
import <iostream>;
import <format>;
import <typeinfo>;         // For use of typeid()

int main()
{
  try
  {
    try
    {
      const size_t size {21};                              // Number of array elements
      const int start {-10};                               // Index for first element
      const int end {start + static_cast<int>(size) - 1};  // Index for last element

      Array<double, start> values {size};                  // Define array of double values

      for (int i {start}; i <= end; ++i)                   // Initialize the elements
        values[i] = i - start + 1;

      std::cout << "Sums of pairs of elements: ";
      size_t lines {};
      for (int i {end}; i >= start; --i)
      {
        std::cout << (lines++ % 5 == 0 ? "\n" : "")
                  << std::format("{:5g}", values[i] + values[i-1]);
      }
    }
    catch (const std::out_of_range& ex)
    {
      std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl;
    }

    // Create array of Box objects
    const int numBoxes {9};
    Array<Box, -numBoxes / 2> boxes { static_cast<size_t>(numBoxes) };    

    for (int i { -numBoxes / 2 }; i <= numBoxes/2 + numBoxes%2; ++i)
      std::cout << std::format("Volume of Box[{}] is {}\n", i, boxes[i].volume());
  }
  catch (const std::exception& ex)
  {
    std::cerr << typeid(ex).name() << " exception caught in main()! "
      << ex.what() << std::endl;
  }
}