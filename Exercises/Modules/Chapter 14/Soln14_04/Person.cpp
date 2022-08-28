// Person class implementation

module person;
import <print>;

Person::Person(size_t age, std::string_view name, Gender gender) 
  : m_age {age}, m_name {name}, m_gender {gender}
{
  // Instead of just initializing the members with the argument values, 
  // you could validate the arguments by doing reasonableness checks. 
  // e.g. Name mustn't be empty, and age should be less than 130 say.
  // To handle a failure sensibly we really need exceptions, 
  // but we don't get to those until chapter 16. 
}

// Display details of Person object
void Person::who() const 
{
  std::println("\nThis is {} who is {} years old.", m_name, m_age);
}

void Person::haveBirthday()
{
	++m_age;
}

std::string_view Person::getGenderString() const
{
  switch (m_gender)
  {
  case Gender::male:   return "a male";
  case Gender::female: return "a female";
  case Gender::other:  return "an other-gendered";
  }

  // Unreachable return statement required by some compilers 
  // (switch statement is exhaustive)
  return {};
}

// Display details of Employee object
void Employee::who() const
{
  std::println("{} is {} employee aged {}.", getName(), getGenderString(), getAge());
}

// Display details of Executive object (execs are particularly sensitive about their age...)
void Executive::who() const
{
  std::println("{} is {} executive.", getName(), getGenderString());
}