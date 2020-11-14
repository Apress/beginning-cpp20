#ifndef ASSERT_H    // Do not forget the #includ guard!
#define ASSERT_H

#include <iostream>
#include <cstdlib> 

/* 
  Only real complication is the need for () around condition to avoid
  expanding to expressions such as !x < y. Best do the same for message
  as well to avoid similar operator precedence issues there.
  This confirms, yet again, that using function-like macros often leads
  to needlessly fragile code.
 */

#define ASSERT(condition, message)       \
  if (!(condition))                      \
  {                                      \
    std::cerr << (message) << std::endl; \
    std::abort();                        \
  }                                      \

#endif // End of the #include guard