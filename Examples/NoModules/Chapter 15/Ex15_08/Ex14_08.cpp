// Calling virtual functions from constructors and destructors
#include "Box.h"
#include "ToughPack.h"

int main()
{
  ToughPack toughPack{ 1.0, 2.0, 3.0 };
  toughPack.showVolume();     // Should show a volume equal to 85% of 1x2x3, or 5.1
}
