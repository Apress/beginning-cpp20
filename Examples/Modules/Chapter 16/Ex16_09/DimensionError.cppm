export module dimension_error;

import <stdexcept>;        // For derived exception classes such as std::out_of_range
import <string>;           // For std::to_string() and the std::string type

export class DimensionError : public std::out_of_range
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
