/*****************************************************************\
 To implement printCount(), you first need a static member variable
 to store the object count. Every constructor should then increment
 this count, and you need to add a destructor that decrements it. 
\*****************************************************************/
module integer;
import <iostream>;

// Constructor
Integer::Integer(int value) : m_value{value}
{
  ++s_count;
  std::cout << "Object created." << std::endl;
}

// Copy constructor
Integer::Integer(const Integer& obj) : m_value{obj.m_value}
{
  ++s_count;
  std::cout << "Object created by copy constructor." << std::endl;
}

// Destructor
Integer::~Integer()
{
  --s_count;
  std::cout << "Object deleted." << std::endl;
}

void Integer::show() const
{
  std::cout << "Value is " << m_value << std::endl;
}

int Integer::compare(const Integer& obj) const
{
  if (m_value < obj.m_value)
    return -1;
  else if (m_value == obj.m_value)
    return 0;
  else
    return 1;
}

void Integer::printCount()
{
  std::cout << "There are now " << s_count << " Integer object(s)." << std::endl;
}