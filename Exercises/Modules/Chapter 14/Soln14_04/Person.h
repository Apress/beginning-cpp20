// Person class and classes derived from Person
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>

/*
  We covered the advantages of the principle of data hiding extensively in Chapter 12.
  In practice, a common convention is to make all data members of a class private. 
  This should thus probably become your default as well. 
  Getter and setter member functions can then be added to either the public 
  or protected interface to control access and/or modifications.
   
  Alternatively, you could make the member variables of Person and Employee themselves protected.
  Often, people take this shortcut because it is somewhat less work:
  then you wouldn't need the protected getter functions.
  However, protected data is a bad idea, much for the same reason as public ones are.
  We refer to the corresponding section in Chapter 14 for a more detailed motivation.
*/

// Possible alternatives for representing a gender include:
//  - a Boolean value, but limited, and which is the 'true' gender?
//  - a char value (say 'm', 'f', 'o'), but then how to enforce that no other values are assigned?
//  - a string ("male", "female", etc), but same problem as with chars (and also excessively expensive)
// The safest, most readable solution is therefore probably an enumeration:
enum class Gender { male, female, other };

class Person
{
public:
  Person() = default;   // Default constructor - necessary to define arrays
  Person(size_t age, std::string_view name, Gender gender);
  
  void who() const;     // Display details
  
  void haveBirthday();

protected:  
  // Functions to allow derived classes to access to a Person's details
  size_t getAge() const    { return m_age; } 
  const std::string& getName() const { return m_name; }
  Gender getGender() const { return m_gender; }
  
  // Convenience function:
  std::string_view getGenderString() const;

private:
  size_t m_age{};      // Age in years
  std::string m_name;
  Gender m_gender{ Gender::female };
};

class Employee : public Person
{
public:
  Employee() = default;   // Default constructor - necessary to define arrays
  Employee(size_t age, std::string_view name, Gender gender, long num)
    : Person{age, name, gender}, m_personnelNumber {num} {}
  
  void who() const;       // Display details

protected:
  long getPersonnelNumber() { return m_personnelNumber; }

private:
  long m_personnelNumber{};
};

class Executive : public Employee
{
public:
  using Employee::Employee;   // Inherit all constructors
  
  void who() const;           // Display details
};

#endif