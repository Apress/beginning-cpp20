// Exercise 3-4. Packing and unpacking characters.

// Strictly speaking, whether or not this program works is compiler-dependent.
// Although it's extremely unlikely that you'll notice a problem.
// Concretely: it'll only work if a single byte is 8 bit (virtually always the case),
// and the fundamental type int counts at least 4 bytes (true for most modern systems).

#include <iostream>
#include <format>

int main()
{
  unsigned int packed {};
  unsigned char ch {};
  std::cout << std::format("{:26}", "Enter a character: ");
  std::cin >> ch;
  packed |= ch;

  std::cout << std::format("{:26}", "Enter a second character: ");
  std::cin >> ch;
  packed <<= 8;                                // Shift left 1 byte
  packed |= ch;

  std::cout << std::format("{:26}", "Enter a third character: ");
  std::cin >> ch;
  packed <<= 8;                                // Shift left 1 byte
  packed |= ch;

  std::cout << std::format("{:26}", "Enter a fourth character: ");
  std::cin >> ch;
  packed <<= 8;                                // Shift left 1 byte
  packed |= ch;

  std::cout << std::format("The word containing 4 packed characters is {:#0x}", packed) << std::endl;
	
  std::cout << "Unpacking the characters again gives (low-order byte first): ";

  // Unpacking packed... 
  // (without the static_cast<char>() conversions the bytes would be written as numbers,
  // which would be fine as well...)

  unsigned int mask {0x00000FF};  // Keep low order byte 
                                  // (could just use 0xFF as well, or, of course, 255)

  ch = packed & mask;                    // Low order byte
  std::cout << std::format("{:4}", static_cast<char>(ch));
  ch = (packed >> 8) & mask;                   // 2nd byte
  std::cout << std::format("{:4}", static_cast<char>(ch));
  ch = (packed >> 16) & mask;                  // 3rd byte
  std::cout << std::format("{:4}", static_cast<char>(ch));
  ch = (packed >> 24) & mask;                  // 4th byte
  std::cout << std::format("{:4}", static_cast<char>(ch)) 
            << std::endl;
}