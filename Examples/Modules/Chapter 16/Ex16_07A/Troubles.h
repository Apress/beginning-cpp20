// MyTroubles.h Exception classes
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
  virtual ~Trouble() = default;   // Base classes must have a virtual destructor!

  virtual std::string_view what() const { return m_message; }
private:
  std::string m_message;
};

// Derived exception class
class MoreTrouble : public Trouble
{
public:
  explicit MoreTrouble(std::string_view str = "There's more trouble...") 
    : Trouble {str} 
  {}
};

// Derived exception class
class BigTrouble : public MoreTrouble
{
public:
  explicit BigTrouble(std::string_view str = "Really big trouble...") 
    : MoreTrouble {str} 
  {}
};

#endif