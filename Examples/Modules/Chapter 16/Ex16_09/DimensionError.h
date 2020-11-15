#ifndef DIMENSION_ERROR_H
#define DIMENSION_ERROR_H

#include <stdexcept>        // For derived exception classes such as std::out_of_range
#include <string>           // For std::to_string() and the std::string type

class DimensionError : public std::out_of_range
{
public:
  explicit DimensionError(double value)
    : std::out_of_range{ "Zero or negative dimension: " + std::to_string(value) }
    , m_value{ value } {}

  // Function to obtain the invalid dimension value
  double getValue() const noexcept { return m_value; }
private:
  double m_value;
};

#endif
