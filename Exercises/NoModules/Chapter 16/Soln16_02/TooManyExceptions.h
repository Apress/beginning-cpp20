// Definition of TooManyExceptions exception class
// We added an extra "how many" members to illustrate derived 
// exceptions can carry extra information regarding their cause.
// Notice how the constructor is explicit (implicit conversions
// from size_t to TooManyExceptions are not desired).

#ifndef TOOMANYEXCEPTIONS_H
#define TOOMANYEXCEPTIONS_H

#include <exception>
#include <string>     // For std::string / std::to_string()

class TooManyExceptions : public std::exception
{
public:
  explicit TooManyExceptions(size_t howMany)
    : m_how_many{ howMany }
    , m_message{ "Too many exceptions occurred: " + std::to_string(m_how_many) }
  {}

  const char* what() const noexcept override
  {
    return m_message.c_str();
  }

  size_t howMany() const noexcept
  {
    return m_how_many;
  }

private:
  size_t m_how_many;
  std::string m_message;
};

#endif //TOOMANYEXCEPTIONS_H