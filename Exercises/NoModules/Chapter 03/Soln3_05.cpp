// Exercise 3-5. Using an enumeration type for colors.
// Of course, you have to research the RGB components for the colors.
// Biggest complication is that you cannot apply any binary or other arithmetic operations
// on values of a scoped enumaration type. For this, you have to first cast them to an integer.

//This program has been modified a little bit
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
/*
Additional notes here: The const auto format_string resulted to compile time error, and i've beeen trying to get my head around the problem,
so I did some research and found out that instead of using "const auto format_string{};", I used "constexp auto format_string{};", and it worked
quite well(what i mean is that, this program compiled and ran and gave corect output).
Now Let me explain: 
Using the "constexpr" keyword instead of const worked because it indicates that the variable "format_string" is required to have a value that can be evaluated at compile time.
Using the const keyword alone doesn't guarantee that the variable will be treated as a compile-time constant.
By using constexpr, you are making it clear to the compiler that the value of format_string will not change and can be known at compile-time, which can provide potential benefits in terms of performance and code generation.
*/
  constexpr auto format_string 
       { "The components of {:^6} are: red: {:3}, green: {:3}, blue: {:3}\n" };
  
  const Color yellow{ Color::Yellow };
  const Color purple{ Color::Purple };
  const Color green { Color::Green };

  std::cout << std::format(format_string,
    "yellow",
    (static_cast<unsigned>(yellow) & static_cast<unsigned>(Color::Red)) >> 16,
    (static_cast<unsigned>(yellow) & static_cast<unsigned>(Color::Green)) >> 8,
    (static_cast<unsigned>(yellow) & static_cast<unsigned>(Color::Blue))
  );

  std::cout << std::format(format_string,
    "purple",
    (static_cast<unsigned>(purple) & static_cast<unsigned>(Color::Red)) >> 16,
    (static_cast<unsigned>(purple) & static_cast<unsigned>(Color::Green)) >> 8,
    (static_cast<unsigned>(purple) & static_cast<unsigned>(Color::Blue))
  );

  std::cout << std::format(format_string,
    "green",
    (static_cast<unsigned>(green) & static_cast<unsigned>(Color::Red)) >> 16,
    (static_cast<unsigned>(green) & static_cast<unsigned>(Color::Green)) >> 8,
    (static_cast<unsigned>(green) & static_cast<unsigned>(Color::Blue))
  );
}
