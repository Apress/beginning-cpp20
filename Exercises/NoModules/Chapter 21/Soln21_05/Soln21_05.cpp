// Exercise 21-5  Recreating std::advance() using constraint-based specialisation
#include <iostream>
#include <iterator>

#include <vector>
#include <list>
#include <forward_list>

template <std::random_access_iterator Iter>
auto my_advance(Iter iter, std::iter_difference_t<Iter> n)
{
  return iter + n;
}

template <std::bidirectional_iterator Iter>
auto my_advance(Iter iter, std::iter_difference_t<Iter> n)
{
  while (n > 0) { ++iter; --n; }
  while (n < 0) { --iter; ++n; }
  return iter;
}

template <std::input_or_output_iterator Iter>
auto my_advance(Iter iter, std::iter_difference_t<Iter> n)
{
  while (n > 0) { ++iter; --n; }
  return iter;
}

int main()
{
  // Random-access iterators:
  std::vector v{ 1, 2, 3, 4, 5 };
  std::cout << *my_advance(v.begin(), 3) << std::endl;

  // Bidirectional iterators:
  std::list l{ 1, 2, 3, 4, 5 };
  std::cout << *my_advance(l.end(), -3) << std::endl;

  // Forward iterators:
  std::forward_list f{ 1, 2, 3, 4, 5 };
  std::cout << *my_advance(f.begin(), 3) << std::endl;
}