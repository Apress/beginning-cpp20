// Constraint based specialization
import <concepts>;  // For the std::equality_comparable<> concept
import <iterator>;  // The iterator concepts and the iter_difference_t<>() trait
import <vector>;
import <list>;
import <iostream>;

// Precondition: incrementing first eventually leads to last
template <std::input_or_output_iterator Iter> requires std::equality_comparable<Iter>
auto distanceBetween(Iter first, Iter last)
{
  std::cout << "Distance determined by linear traversal: ";
  std::iter_difference_t<Iter> result{};
  while (first != last) { ++first; ++result; }
  return result;
}

template <std::random_access_iterator Iter>
auto distanceBetween(Iter first, Iter last)
{
  std::cout << "Distance determined in constant time: ";
  return last - first;
}

int main()
{
  std::list l{ 'a', 'b', 'c' };
  std::vector v{ 1, 2, 3, 4, 5 };
  float a[] { 1.2f, 3.4f, 4.5f };

  std::cout << distanceBetween(cbegin(l), cend(l)) << std::endl;
  std::cout << distanceBetween(begin(v), end(v)) << std::endl;
  std::cout << distanceBetween(a, a + std::size(a)) << std::endl;
}
