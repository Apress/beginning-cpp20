// Using the bitwise operators
import <iostream>;
import <format>;

int main()
{
  const unsigned int red{ 0xFF0000u };   // Color red
  const unsigned int white{ 0xFFFFFFu }; // Color white - RGB all maximum

  std::cout << "Try out bitwise complement, AND and OR operators:\n";
  std::cout << std::format("Initial value:       red = {:08X}\n", red);
  std::cout << std::format("Complement:         ~red = {:08X}\n", ~red);

  std::cout << std::format("Initial value:     white = {:08X}\n", white);
  std::cout << std::format("Complement:       ~white = {:08X}\n", ~white);

  std::cout << std::format("Bitwise AND: red & white = {:08X}\n", red & white);
  std::cout << std::format("Bitwise  OR: red | white = {:08X}\n", red | white);

  std::cout << "\nNow try successive exclusive OR operations:\n";
  unsigned int mask{ red ^ white };
  std::cout << std::format("mask = red ^ white = {:08X}\n", mask);
  std::cout << std::format("        mask ^ red = {:08X}\n", mask ^ red);
  std::cout << std::format("      mask ^ white = {:08X}\n", mask ^ white);

  unsigned int flags{ 0xFF };            // Flags variable
  unsigned int bit1mask{ 0x1 };          // Selects bit 1
  unsigned int bit6mask{ 0b100000 };     // Selects bit 6
  unsigned int bit20mask{ 1u << 19 };    // Selects bit 20

  std::cout << "Use masks to select or set a particular flag bit:\n";
  std::cout << std::format("Select bit 1 from flags  : {:08X}\n", flags & bit1mask);
  std::cout << std::format("Select bit 6 from flags  : {:08X}\n", flags & bit6mask);
  std::cout << std::format("Switch off bit 6 in flags: {:08X}\n", flags &= ~bit6mask);
  std::cout << std::format("Switch on bit 20 in flags: {:08X}\n", flags |= bit20mask);
}
