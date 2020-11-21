export module pair;

import <compare>;
import <iostream>;

export template <typename First, typename Second>
class Pair
{
public:
  // Public members + no m_ prefix analogous to std::pair<> (see <utility> module)
  First first;    
  Second second;

  Pair() = default;
  Pair(const First& f, const Second& s);
  
  // Note: not all compiler may fully support this generation yet (C++20)...
  // (replacing auto with std::strong_ordering may make Soln17_02.cpp compile then,
  // but in general auto is better because First and/or Second could be types 
  // that are not strongly ordered, such as a floating-point types)
  auto operator<=>(const Pair& other) const = default;
};

// Constructor
template <typename First, typename Second>
Pair<First, Second>::Pair(const First& f, const Second& s)
  : first{f}, second{s}
{}

export template <typename First, typename Second>
std::ostream& operator<<(std::ostream& out, const Pair<First, Second>& pair)
{
  return out << '(' << pair.first << ", " << pair.second << ')';
}
