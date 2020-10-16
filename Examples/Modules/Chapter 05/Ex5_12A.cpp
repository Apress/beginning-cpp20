// Allocating an array at runtime (for loop merged into preceding while loop)
// This example does not work with some compilers (such as Visual C++)
// because dynamic arrays is not standard C++ (it is valid C though).
import <iostream>;
import <format>;

#ifdef _MSC_VER   // See Appendix A for an explanation of preprocessing macros
  #error Visual Studio does not support variable length arrays (not standard C++)
#endif

int main()
{
  size_t count {};
  std::cout << "How many heights will you enter? ";
  std::cin >> count;
  int height[count];            // Create the array of count elements

  // Read the heights
  unsigned int total {};
  size_t entered {};
  while (entered < count)
  {
    std::cout << "Enter a height (in inches): ";
    std::cin >> height[entered];
    if (height[entered] > 0)          // Make sure value is positive
    {
      total += height[entered++];
    }
    else
    {
      std::cout << "A height must be positive - try again.\n";
    }
  }

  std::cout << std::format("The average height is {:.1f}\n",
                              static_cast<float>(total) / count);
}
