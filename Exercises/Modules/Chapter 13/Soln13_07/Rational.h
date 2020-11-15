// Rational.h

#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
public:
  // Constructor
  Rational(int numerator = 0, int denominator = 1) 
    : m_numerator {numerator}, m_denominator {denominator}
  {}

  // Accessors
  int getNumerator() const { return m_numerator; }
  int getDenominator() const { return m_denominator; }
  
  // Mutators
  void setNumerator(int numerator) { m_numerator = numerator; }
  void setDenominator(int denominator) { m_denominator = denominator; }
  
  // Casting operators (could be non-explicit as well: is a matter of taste)
  explicit operator double() const { return static_cast<double>(m_numerator) / m_denominator; }
  explicit operator float() const { return static_cast<float>(m_numerator) / m_denominator; }
  
  // Full support for all comparison operators with both Rational and double
  // through the magic of the spaceship operator. 
  // The only other operator you need to define here is equality
  // (because the spaceship operator cannot be defaulted).
  auto operator<=>(const Rational& other)
  {
    return m_numerator * other.m_denominator <=> other.m_numerator * m_denominator;
  }
  auto operator<=>(double value)
  {
    return static_cast<double>(*this) <=> value;
  }
  bool operator==(const Rational& other)
  {
    return m_numerator * other.m_denominator == other.m_numerator * m_denominator;
  }
  bool operator==(double value)
  {
    return static_cast<double>(*this) == value;
  }

  // Unary arithmetic operator
  Rational operator-() const { return Rational{-m_numerator, m_denominator}; }   
  
  // A Rational is false if and only if its numerator equals zero.
  // Note: for operator bool(), we used explicit here to sidestep ambiguities with other operators.
  // We did not add operator!, 
  // because this conversion operator covers all use in Boolean expressions 
  // (see also previous exercise).
  explicit operator bool() const  { return m_numerator != 0; }         
  
  // Compound assignment operators
  Rational& operator+=(const Rational& other)
  {
    m_numerator = m_numerator * other.m_denominator + other.m_numerator * m_denominator;
    m_denominator = m_denominator * other.m_denominator;
    return *this;
  };
  Rational& operator-=(const Rational& other)
  { 
    m_numerator = m_numerator * other.m_denominator - other.m_numerator * m_denominator;
    m_denominator = m_denominator * other.m_denominator;
    return *this;
  };
  Rational& operator*=(const Rational& other)
  { 
    m_numerator *= other.m_numerator;
	  m_denominator *= other.m_denominator;
	  return *this;
  };
  Rational& operator/=(const Rational& other)
  { 
    m_numerator *= other.m_denominator;
    m_denominator *= other.m_numerator;
    return *this;
  };

  // Prefix and postfix increment and decrement operators
  Rational& operator++() 
  { 
    m_numerator += m_denominator;
    return *this;
  }
  const Rational operator++(int)
  {
    auto copy(*this);   // Create a copy of the current object
    ++(*this);          // Increment the current object using the prefix operator...
    return copy;        // Return the unincremented copy
  }
  Rational& operator--() 
  { 
    m_numerator -= m_denominator;
    return *this;
  }

  const Rational operator--(int)
  {
    auto copy(*this);   // Create a copy of the current object
    --(*this);          // Increment the current object using the prefix operator...
    return copy;        // Return the unincremented copy
  }

private:
  int m_numerator, m_denominator;
};

// Stream output operator
inline std::ostream& operator<<(std::ostream& stream, const Rational& r)
{
	return stream << r.getNumerator() << '/' << r.getDenominator();
}

// Binary arithmetic operators: non-member functions to allow for implicit conversions
// This allows expressions such as 2 * (myRationale + 1)
inline Rational operator+(const Rational& one, const Rational& other) { auto copy{ one }; return copy += other; }
inline Rational operator-(const Rational& one, const Rational& other) { auto copy{ one }; return copy -= other; }
inline Rational operator*(const Rational& one, const Rational& other) { auto copy{ one }; return copy *= other; }
inline Rational operator/(const Rational& one, const Rational& other) { auto copy{ one }; return copy /= other; }

#endif