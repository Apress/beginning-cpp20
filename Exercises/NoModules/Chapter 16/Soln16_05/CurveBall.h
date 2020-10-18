// Definition of CurveBall exception class

#ifndef CURVEBALL_H
#define CURVEBALL_H
#include <exception>

class CurveBall : public std::exception
{
public:
  const char* what() const noexcept override
  {
    return "CurveBall exception";
  }
};

#endif //CURVEBALL_H