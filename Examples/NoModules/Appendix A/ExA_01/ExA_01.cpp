// Defining object-like macros
#include <iostream>

#define POINTER_SIZE sizeof(int*) * BITS_PER_BYTE
#define BITS_PER_BYTE 8

int main()
{
  std::cout << POINTER_SIZE << std::endl;   // 32 or 64, normally
}

// The next macro (while providing a perfectly valid definition for "main") 
// is never applied, because it is not defined yet when the preprocessor 
// processes the line "int main()".
#define main Of chief or leading importance; prime, principal.
