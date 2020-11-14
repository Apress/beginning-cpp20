/***************************************************************\
 This header shows two distinct ways of allowing an Integer
 to be constructed without an argument:
  1) The first is to add a default constructor. 
	   To make sure m_value is zero, 
     it adds zero initialization to the declaration of m_value.
  2) The second (at the bottom of the file) is commented out 
     and uses a default parameter value for the existing 
     single-argument constructor.
\***************************************************************/

#ifndef INTEGER_H
#define INTEGER_H

// Option 1: zero-initialize n and add a default constructor
class Integer
{
public:
  Integer() = default;                     // Zero-arg constructor
  Integer(int value);                      // Contructor with given value
  Integer(const Integer& obj);             // Copy constructor

  int getValue() const { return m_value; }
  void setValue(int value) { m_value = value; }

//  int compare(Integer obj) const;        // Compare function with value parameter
  int compare(const Integer& obj) const;   // Compare function with reference parameter

  void show() const;

private:
  int m_value{};
};

// Option 2: use zero a default parameter value
/*
class Integer
{
public:
  Integer(int value = 0);                  // Contructor with given value

  int getValue() const { return m_value; }
  void setValue(int value) { m_value = value; }

//  int compare(Integer obj) const;        // Compare function with value parameter
  int compare(const Integer& obj) const;   // Compare function with reference parameter

  void show() const;

private:
  int m_value;
};
*/

#endif