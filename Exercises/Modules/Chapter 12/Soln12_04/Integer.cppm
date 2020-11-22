export module integer;

export class Integer
{
public:
  Integer(int value = 0);
  Integer(const Integer& obj);
  
  int getValue() const { return m_value; }
  void setValue(int value) { m_value = value; }

  void show() const;

  friend int compare(const Integer& obj1, const Integer& obj2);  // friend compare function

private:
  int m_value;
};

// A non-friend function that implements the same function
export int nonFriendCompare(const Integer& obj1, const Integer& obj2);
