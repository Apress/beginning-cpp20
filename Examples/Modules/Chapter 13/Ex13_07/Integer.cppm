#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
public:
  Integer(int value = 0) : m_value{value} {}
  int getValue() const { return m_value; }
  void setValue(int value) { m_value = value; }
private:
  int m_value;
};

inline Integer operator+(const Integer& one, const Integer& other)
{
  return one.getValue() + other.getValue();
}
inline Integer operator-(const Integer& one, const Integer& other)
{
  return one.getValue() - other.getValue();
}
inline Integer operator*(const Integer& one, const Integer& other)
{
  return one.getValue() * other.getValue();
}
inline Integer operator/(const Integer& one, const Integer& other)
{
  return one.getValue() / other.getValue();
}
inline Integer operator%(const Integer& one, const Integer& other)
{
  return one.getValue() % other.getValue();
}

#endif
