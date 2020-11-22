module integer;
import <iostream>;

/****************************************************************\
 Implementing compare() as a friend is quite simple.
 We must declare the function as a friend in the class definition.
 We now need both objects as arguments and the code in the
 body of the function just compares the n members of the arguments.
 Both parameters are references-to-const.

 However, other than the need for you to exercise friend functions,
 there's no real reason for the compare() function to be a friend
 of the Integer class: it can be implemented perfectly fine
 using the public getValue() function as well.
 The nonFriendCompare() function given below is therefore 
 preferred over a friend function.
\****************************************************************/


// Constructor
Integer::Integer(int value) : m_value{value}
{
  std::cout << "Object created." << std::endl;
}

// Copy constructor
Integer::Integer(const Integer& obj) : m_value{ obj.m_value }
{
  std::cout << "Object created by copy constructor." << std::endl;
}

void Integer::show() const
{
  std::cout << "Value is " << m_value << std::endl;
}

// friend compare function
int compare(const Integer& obj1, const Integer& obj2)
{
  if (obj1.m_value < obj2.m_value)
    return -1;
  else if (obj1.m_value == obj2.m_value)
    return 0;
  else
	  return 1;
}

// non-friend compare function
int nonFriendCompare(const Integer& obj1, const Integer& obj2)
{
  if (obj1.getValue() < obj2.getValue())
    return -1;
  else if (obj1.getValue() == obj2.getValue())
    return 0;
  else
  	return 1;
}