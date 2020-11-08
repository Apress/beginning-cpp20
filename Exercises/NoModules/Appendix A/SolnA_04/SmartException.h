#ifndef SMART_EXCEPTION_H
#define SMART_EXCEPTION_H

#include <stdexcept>
#include <source_location>

class SmartException : public std::logic_error
{
public:
  SmartException(const std::string& message, std::source_location location = std::source_location::current())
    : std::logic_error{ message }
    , m_location(location)
  {
  }

  /* Throws the exception at this location
   * For cases where the exception is not created at the same line where it is thrown:
   *   SmartException exception("BOOM!", {});   // Optional: do not use std::source_location::current() yet
   *   ... // more code
   *   exception.throwFromHere();
   */
  void throwFromHere(std::source_location location = std::source_location::current());

  const std::source_location& where() const;

private:
  std::source_location m_location;
};

// Note: do not repeat the default argument value!
inline void SmartException::throwFromHere(std::source_location location)
{
  throw* this;
}

inline const std::source_location& SmartException::where() const
{
  return m_location;
}

#endif
