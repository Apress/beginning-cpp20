// Finding maximum and minimum values for data types
import <iostream>;
import <limits>;
import <format>;

int main()
{
  std::cout
    << std::format("The range for type short is from {} to {}\n",
      std::numeric_limits<short>::min(), std::numeric_limits<short>::max())
    << std::format("The range for type unsigned int is from {} to {}\n",
      std::numeric_limits<unsigned int>::min(),
      std::numeric_limits<unsigned int>::max())
    << std::format("The range for type long is from {} to {}\n",
      std::numeric_limits<long>::min(), std::numeric_limits<long>::max())
    << std::format("The positive range for type float is from {} to {}\n",
      std::numeric_limits<float>::min(), std::numeric_limits<float>::max())
    << std::format("The full range for type float is from {} to {}\n",
      std::numeric_limits<float>::lowest(), std::numeric_limits<float>::max())
    << std::format("The positive range for type double is from {} to {}\n",
      std::numeric_limits<double>::min(),
      std::numeric_limits<double>::max())
    << std::format("The positive range for type long double is from {} to {}\n",
      std::numeric_limits<long double>::min(),
      std::numeric_limits<long double>::max());
}
