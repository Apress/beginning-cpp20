// Calling virtual functions from constructors and destructors
import boxes;

int main()
{
  ToughPack toughPack{ 1.0, 2.0, 3.0 };
  toughPack.printVolume();   // Should print a volume equal to 87% of 1x2x3, or 5.1
}
