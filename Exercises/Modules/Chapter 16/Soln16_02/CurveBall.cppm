// Definition of CurveBall exception class

#ifndef CURVEBALL_H
#define CURVEBALL_H
import <exception>;

class CurveBall : public std::exception
{
public:
  const char* what() const noexcept override
  {
    return "CurveBall exception";
  }
};

 //CURVEBALL_H