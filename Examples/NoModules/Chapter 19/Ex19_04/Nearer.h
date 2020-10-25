// A class of function objects that compare two values based on how close they are 
// to some third value that was provided to the functor at construction time.
#ifndef NEARER_H
#define NEARER_H

#include <cmath>   // For std::abs()

class Nearer
{
public:
  explicit Nearer(int value) : m_value{ value } {}
  bool operator()(int x, int y) const
  { 
    return std::abs(x - m_value) < std::abs(y - m_value); 
  }
private:
  int m_value;
};

#endif