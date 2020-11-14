#ifndef ASSERT_H
#define ASSERT_H

#include <iostream>
#include <cstdlib> 

#ifndef NDEBUG
  #define ASSERT(condition, message)       \
    if (!(condition))                      \
    {                                      \
      std::cerr << (message) << std::endl; \
      std::abort();                        \
    }
#else
  #define ASSERT(condition, message)
#endif

#endif // End of the #include guard