#include "PrintThis.h"

// Note: extern keyword is optional, 
// but does make clear that external linkage is used here.
extern void print(std::string_view string);

void print_this(std::string_view string)
{
  print(string);
}
