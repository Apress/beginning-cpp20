// Exercise 3-6. Using an enumeration type for colors.
// Of course, you have to research the RBG components for the colors.
// Biggest complication is that you cannot apply any binary or other arithmetic operations
// on values of a scoped enumaration type. For this, you have to first cast them to an integer.

#include <iostream>
#include <format>

int main()
{
  enum class Color : unsigned
  {
    Red    = 0xFF0000u,
    Green  = 0x00FF00u,
    Blue   = 0x0000FFu,
    Yellow = 0xFFFF00u,
    Purple = 0xFF00FFu,
    Black  = 0x000000u,
    White  = 0xFFFFFFu
  };

  const auto format_string 
       { "The components of {:^6} are: red: {:3}, green: {:3}, blue: {:3}\n" };
  
  std::cout << std::format(format_string,
    "yellow",
    (static_cast<unsigned>(Color::Yellow) & static_cast<unsigned>(Color::Red)) >> 16,
    (static_cast<unsigned>(Color::Yellow) & static_cast<unsigned>(Color::Green)) >> 8,
    (static_cast<unsigned>(Color::Yellow) & static_cast<unsigned>(Color::Blue))
  );

  std::cout << std::format(format_string,
    "purple",
    (static_cast<unsigned>(Color::Purple) & static_cast<unsigned>(Color::Red)) >> 16,
    (static_cast<unsigned>(Color::Purple) & static_cast<unsigned>(Color::Green)) >> 8,
    (static_cast<unsigned>(Color::Purple) & static_cast<unsigned>(Color::Blue))
  );

  std::cout << std::format(format_string,
    "green",
    (static_cast<unsigned>(Color::Green) & static_cast<unsigned>(Color::Red)) >> 16,
    (static_cast<unsigned>(Color::Green) & static_cast<unsigned>(Color::Green)) >> 8,
    (static_cast<unsigned>(Color::Green) & static_cast<unsigned>(Color::Blue))
  );
}