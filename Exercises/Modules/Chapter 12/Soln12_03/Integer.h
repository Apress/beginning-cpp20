#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
public:
  Integer(int value = 0);
  Integer(const Integer& obj);

  int getValue() const { return m_value; }
  void setValue(int value) { m_value = value; }
  
  Integer& add(const Integer& obj);
  Integer& subtract(const Integer& obj);
  Integer& multiply(const Integer& obj);

  int compare(const Integer& obj) const;
  
  void show() const;

private:
  int m_value;
};

#endif