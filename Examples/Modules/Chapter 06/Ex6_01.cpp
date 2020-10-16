// The size of pointers
import <iostream>;

int main()
{
  // Print out the size (in number of bytes) of some data types
  // and the corresponding pointer types:
  std::cout << sizeof(double)  << " > "  << sizeof(char16_t)  << std::endl;
  std::cout << sizeof(double*) << " == " << sizeof(char16_t*) << std::endl;
}
