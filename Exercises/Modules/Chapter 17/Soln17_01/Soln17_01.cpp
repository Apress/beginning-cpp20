// Adding a push_back() member function and a default constructor to the Array<> 
// class template. Using copy-and-swap for a memory-safe push_back().
#include "Array.h"
#include <iostream>

int main()
{
  const unsigned numElements{ 100 };

  Array<unsigned> squares;       // default construction
  for (unsigned i {}; i < numElements; ++i)
	  squares.push_back(i * i);    // push_back()

  std::cout << squares.getSize() << " squares were added." << std::endl;
  std::cout << "For instance: 13 squared equals " << squares[13] << std::endl;
}