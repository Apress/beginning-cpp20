#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
public:
  Integer(int value);
  int getValue() const { return m_value; }
  void setValue(int value) { m_value = value; }
  void show() const;

private:
  int m_value;
};

#endif