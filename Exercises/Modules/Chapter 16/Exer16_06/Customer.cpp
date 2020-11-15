// A simple C++ customer class

#include "Customer.h"

Customer::Customer(
      std::string_view surname,
      std::string_view name,
      std::string_view street,
      int streetNumber,
      std::string_view city)
  : m_surname{ surname }
  , m_name{ name }
  , m_street{ street }
  , m_streetNumber{ streetNumber }
  , m_city{ city }
{}

std::string Customer::toString() const
{
  std::string result;
  result += m_surname;
  result += ' ';
  result += m_name;
  result += ", ";
  result += m_street;
  result += ' ';
  result += std::to_string(m_streetNumber);
  result += ", ";
  result += m_city;
  return result;
}