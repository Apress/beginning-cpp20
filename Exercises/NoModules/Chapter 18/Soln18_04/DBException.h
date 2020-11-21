// A simple C++ exception type

#ifndef DB_EXCEPTION_H
#define DB_EXCEPTION_H

#include <stdexcept>

class DatabaseException : public std::runtime_error
{
public:
  using std::runtime_error::runtime_error;  // Inherit constructor
};

#endif