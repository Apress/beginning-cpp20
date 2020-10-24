#ifndef BOX_FORMATTER_H
#define BOX_FORMATTER_H

#include "Box.h"
#include <format>

// Adding specific specializations to the std namespace is allowed
template <>
class std::formatter<Box> : public std::formatter<double>
{
public:
  
  /* This was no easy exercise. Fixes required compared to the outline in the exercise:
      - the member is called advance_to() and not advance() 
        (we actually used advance() by mistake in the book, but hey, 
         it did force you to practice consulting a Standard Library reference?)
      - you need to specify std::formatter<double> to access the base class format() function
      - of course you still needed to add "Box(., ., .)" as well.
        One way to do this is repeatedly call std::format_to(),
        a function similar to std::format() except that it outputs not to a stream but an output iterator.
        You can also manipulate the iterator directly, as we show in for outputting 
        the second ", " and the ")".
        (Iterator manipulation is explained in more detail in Chapter 20...)
   */
  auto format(const Box& box, auto& context)
  {
    auto iter{ std::format_to(context.out(), "Box(") };
    context.advance_to(iter);
    iter = std::formatter<double>::format(box.getLength(), context);
    iter = std::format_to(iter, ", ");
    context.advance_to(iter);
    iter = std::formatter<double>::format(box.getWidth(), context);
    *iter++ = ',';
    *iter++ = ' ';
    context.advance_to(iter);
    std::formatter<double>::format(box.getHeight(), context);
    *iter++ = ')';
    context.advance_to(iter);
    return iter;
  }
};

#endif
