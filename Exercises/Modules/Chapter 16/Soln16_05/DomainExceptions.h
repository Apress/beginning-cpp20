// Definitions of various domain exception classes
#ifndef DOMAINEXCEPTIONS_H
#define DOMAINEXCEPTIONS_H

#include <stdexcept>
#include <string>

/*
	std::domain_error is one of the exception types defined by
	the Standard Libray. It is intended to be used mostly inside
	mathematical functions in case an argument is provided for which
	the function is not defined (for instance, should a regular 
	square root function be called with a negative number)
*/

class NotANumber : public std::domain_error
{
public:
  explicit NotANumber(const std::string& nan) 
    : std::domain_error{"Not a number: " + nan} 
  {}
};

class NegativeNumber : public std::domain_error
{
public:
  explicit NegativeNumber(int number)
    : std::domain_error{"A negative number was entered: " + std::to_string(number)}
  {}
};

class OddNumber : public std::domain_error
{
public:
  explicit OddNumber(int number)
    : std::domain_error{"An odd number was entered: " + std::to_string(number)}
  {}
};

#endif //DOMAINEXCEPTIONS_H