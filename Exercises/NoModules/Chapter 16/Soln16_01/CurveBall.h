// Definition of Curveball exception class

#ifndef CURVEBALL_H
#define CURVEBALL_H
#include <exception>

class Curveball : public std::exception
{
public:
  const char* what() const noexcept override
  {
    return "Curveball exception";
  }
};

#endif //CURVEBALL_H