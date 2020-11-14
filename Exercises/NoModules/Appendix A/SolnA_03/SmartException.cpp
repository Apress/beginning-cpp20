#include "SmartException.h"

SmartException::SmartException(const std::string& message, std::source_location location)
  : std::logic_error{ message }
  , m_location{ std::move(location) }
{
}

void SmartException::throwFromHere(std::source_location location)
{
  m_location = std::move(location);
  throw *this;
}

const std::source_location& SmartException::where() const
{
  return m_location;
}
