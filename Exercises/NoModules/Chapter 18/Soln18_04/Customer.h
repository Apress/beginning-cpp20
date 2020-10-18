// A simple C++ customer class

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <string_view>

class Customer
{
public:
  Customer(
      std::string_view surname,
      std::string_view name,
      std::string_view street,
      int streetNumber,
      std::string_view city
  );

  std::string toString() const;
  
private:
  std::string m_surname;
  std::string m_name;
  std::string m_street;
  int m_streetNumber;
  std::string m_city;
};

#endif