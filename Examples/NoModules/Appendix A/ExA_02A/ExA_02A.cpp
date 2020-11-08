// Fun with line continuations
#include <iostream>

#define DEFINE_PRINT_FUNCT\
ION(NAME, COUNT, VALUE) vo\
id NAME##COUNT() { std::co\
ut << #VALUE << std::endl; }

DEFINE_PRINT_FUNCTION(fun, 123, Test 1 "2" 3)

\
i\
nt\
 ma\
in()\
{fun1\
23();}\
