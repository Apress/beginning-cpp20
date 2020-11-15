export module integer;

export class Integer
{
public:
  Integer(int value = 0) : m_value{value} {}
  int getValue() const { return m_value; }
  void setValue(int value) { m_value = value; }
private:
  int m_value;
};

export Integer operator+(const Integer& one, const Integer& other)
{
  return one.getValue() + other.getValue();
}
export Integer operator-(const Integer& one, const Integer& other)
{
  return one.getValue() - other.getValue();
}
export Integer operator*(const Integer& one, const Integer& other)
{
  return one.getValue() * other.getValue();
}
export Integer operator/(const Integer& one, const Integer& other)
{
  return one.getValue() / other.getValue();
}
export Integer operator%(const Integer& one, const Integer& other)
{
  return one.getValue() % other.getValue();
}
