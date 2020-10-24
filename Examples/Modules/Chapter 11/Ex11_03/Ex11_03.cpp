// Using types with reachable definitions but whose names are not visible
import <iostream>;
import roman;

int main()
{
  // std::string_view is reachable, so its constructor can be invoked 
  // (this constructor, unlike the std::string_view name itself, is visible)
  std::cout << "MMXX in Arabic numerals is " << from_roman("MMXX") << std::endl;

  // The names of the c_str() and size() members are visible as well
  // (because the definition of std::string is reachable), 
  // and can thus be invoked.
  std::cout << "1234 in Roman numerals is " << to_roman(1234).c_str() << std::endl;
  std::cout << "This consists of " << to_roman(1234).size() << " numerals" << std::endl;

  // std::string_view s{ "MMXX" };   /* Error: the name std::string_view is not visible */
  // std::string roman{ to_roman(567) };  /* Error: the name std::string is not visible */

  auto roman{ to_roman(567) };
  std::cout << "567 in Roman numerals is " << roman.c_str() << std::endl;

  // std::cout << "std::stoi() is not visible: " << std::stoi("1234") << std::endl;

  // The << operator (which is implemented as a non-member function) is not visible either
  // std::cout << "1234 in Roman numerals is " << to_roman(1234) << std::endl;
}
