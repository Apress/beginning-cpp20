#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
public:
  Integer(int m = 0);                      // Contructor with given value
  Integer(const Integer& obj);             // Copy constructor
  ~Integer();                              // Destructor

  int getValue() const { return m_value; }
  void setValue(int m) { m_value = m; }

  int compare(const Integer& obj) const;   // Compare function with reference parameter

  void show() const;
  
  static void printCount();

private:
  int m_value;
  static inline unsigned int s_count {};
};

#endif