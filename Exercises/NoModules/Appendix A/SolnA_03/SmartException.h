#ifndef SMART_EXCEPTION_H
#define SMART_EXCEPTION_H

#include <stdexcept>
#include <source_location>

class SmartException : public std::logic_error
{
public:
  SmartException(const std::string& message, std::source_location location = std::source_location::current());

  /* Throws the exception at this location
   * For cases where the exception is not created at the same line where it is thrown:
   *   SmartException exception{ "BOOM!", {} };
   *   ... // more code
   *   exception.throwFromHere();
   * Note: in the example above, {} is optional 
   * (it avoids calling std::source_location::current() during construction)
   */
  void throwFromHere(std::source_location location = std::source_location::current());

  const std::source_location& where() const;

private:
  std::source_location m_location;
};

#endif
