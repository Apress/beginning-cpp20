// Program that lists its command line arguments
#include <iostream>

int  main(int argc, char* argv[])
{
  for (int i{}; i < argc; ++i)
    std::cout << argv[i] << std::endl;
}
