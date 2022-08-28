// Using the bitwise operators
import <print>;

int main()
{
  const unsigned int red{ 0xFF0000u };   // Color red
  const unsigned int white{ 0xFFFFFFu }; // Color white - RGB all maximum

  std::println("Try out bitwise complement, AND and OR operators:");
  std::println("Initial value:       red = {:08X}", red);
  std::println("Complement:         ~red = {:08X}", ~red);

  std::println("Initial value:     white = {:08X}", white);
  std::println("Complement:       ~white = {:08X}", ~white);

  std::println("Bitwise AND: red & white = {:08X}", red & white);
  std::println("Bitwise  OR: red | white = {:08X}", red | white);

  std::println("\nNow try successive exclusive OR operations:");
  unsigned int mask{ red ^ white };
  std::println("mask = red ^ white = {:08X}", mask);
  std::println("        mask ^ red = {:08X}", mask ^ red);
  std::println("      mask ^ white = {:08X}", mask ^ white);

  unsigned int flags{ 0xFF };            // Flags variable
  unsigned int bit1mask{ 0x1 };          // Selects bit 1
  unsigned int bit6mask{ 0b100000 };     // Selects bit 6
  unsigned int bit20mask{ 1u << 19 };    // Selects bit 20

  std::println("Use masks to select or set a particular flag bit:");
  std::println("Select bit 1 from flags  : {:08X}", flags & bit1mask);
  std::println("Select bit 6 from flags  : {:08X}", flags & bit6mask);
  std::println("Switch off bit 6 in flags: {:08X}", flags &= ~bit6mask);
  std::println("Switch on bit 20 in flags: {:08X}", flags |= bit20mask);
}
