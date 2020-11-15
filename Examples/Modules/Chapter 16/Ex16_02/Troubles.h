// Exception class definition
#ifndef MYTROUBLES_H
#define MYTROUBLES_H
#include <string>
#include <string_view>

class Trouble
{
public:
  explicit Trouble(std::string_view message = "There's a problem") 
    : m_message {message} 
  {}
  std::string_view what() const { return m_message; }
private:
  std::string m_message;
};

#endif
