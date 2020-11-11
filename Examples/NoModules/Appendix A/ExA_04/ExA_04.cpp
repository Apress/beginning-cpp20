// Demonstrating assertions
#include <iostream>
#include <format>

// Uncomment to disable the assertion in main() (needs to be defined before including <cassert>)
//#define NDEBUG
#include <cassert> 

int main()
{
  int y{ 5 };

  for (int x{}; x < 20; ++x)
  {
    std::cout << std::format("x = {}\ty = {}", x, y) << std::endl;
    assert(x < y);
  }
}

// A static assertion (comment out to build as a 32-bit program)
static_assert(sizeof(int*) > 4, "32-bit compilation is not supported.");