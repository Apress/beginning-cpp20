// Exercise 3-4. Packing and unpacking characters.

// Strictly speaking, whether or not this program works is compiler-dependent.
// Although it's extremely unlike that you'll notice a problem.
// Concretely: it'll only work if a single byte is 8 bit (virtually always the case),
// and the fundamental type int counts at least 4 bytes (true for most modern systems).

#include <iostream>
#include <iomanip>

int main()
{
  unsigned int packed {};
  unsigned char ch {};
  std::cout << std::left << std::setw(26) << "Enter a character: ";
  std::cin >> ch;
  packed |= ch;

  std::cout << std::setw(26) << "Enter a second character: ";
  std::cin >> ch;
  packed <<= 8;                                // Shift left 1 byte
  packed |= ch;

  std::cout << std::setw(26) << "Enter a third character: ";
  std::cin >> ch;
  packed <<= 8;                                // Shift left 1 byte
  packed |= ch;

  std::cout << std::setw(26) << "Enter a fourth character: ";
  std::cin >> ch;
  packed <<= 8;                                // Shift left 1 byte
  packed |= ch;

  std::cout << "The word containing 4 packed characters is " << std::right
    << std::hex << std::showbase << std::internal << std::setfill('0') << packed << std::endl;

  std::cout << std::setfill(' ');
	
  // Unpacking packed...
  unsigned int mask {0x000000FF};              // Keep low order byte
  ch = mask & packed;                          // Low order byte
  std::cout << std::setw(4) << ch;
  ch = mask & (packed >> 8);                   // 2nd byte
  std::cout << std::setw(4) << ch;
  ch = mask & (packed >> 16);                  // 3rd byte
  std::cout << std::setw(4) << ch;
  ch = mask & (packed >> 24);                  // 4th byte
  std::cout << std::setw(4) << ch << std::endl;
}