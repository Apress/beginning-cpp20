// Exercise 21-2  Writing a proper, modern algorithm is hard...
// It involves adding support for projection, member pointers,
// and iterator pairs where the end iterator (or, sentinel) 
// is of a different type than the begin iterator,
// all with proper type constraints.
#include <iostream>
#include <concepts>    // Standard concepts
#include <ranges>      // Range factories and adaptors
#include <functional>  // For the std::identity and std::ranges::less functor classes, and std::invoke()
#include <iterator>    // Iterator-based concepts, std::sentinel_for, and std::projected
#include <vector>

using namespace std::ranges::views;

// The original function template which requires begin and end to be of the same type
// Similar to the original iterator-pair based algorithms of <algorithm>,
// only with type constraints.
template <std::forward_iterator Iterator,
          std::indirect_strict_weak_order<Iterator> Comparison>
Iterator original_find_optimum(Iterator begin, Iterator end, Comparison compare)
{
  if (begin == end) return end;

  Iterator optimum{ begin };
  for (auto iter{ ++begin }; iter != end; ++iter)
  {
    if (compare(*iter, *optimum)) optimum = iter;
  }
  return optimum;
}

// Our improved function template supporting projection and differently-typed sentinels.
// Appropriate default values were added as well.
template <std::forward_iterator Iterator,
          std::sentinel_for<Iterator> Sentinel, 
          typename Projection = std::identity,
          std::indirect_strict_weak_order<std::projected<Iterator, Projection>> Comparison = std::ranges::less>
Iterator find_optimum(Iterator begin, Sentinel end, Comparison compare = {}, Projection projection = {})
{
  if (begin == end) return begin; // Do not return end as before...

  Iterator optimum{ begin };
  for (auto iter{ ++begin }; iter != end; ++iter)
  {
    // Note 1: std::invoke() is required to support comparison and projection through member pointers 
    // Note 2: this re-invokes projection(*optimum) for each comparison, same as std::max_element()
    if (std::invoke(compare, std::invoke(projection, *iter), std::invoke(projection, *optimum)))
      optimum = iter;
  }
  return optimum;
}

/* A simple Box class to exercise our member-based comparison and projection facilities.
  It lacks an operator<(), so with classical algorithms you'd need lambdas to compare these Boxes...
 */
class Box
{
public:
  Box() : Box{ 1, 1, 1 } {};
  Box(double length, double width, double height)
    : m_length{ length }, m_width{ width }, m_height{ height }
  {}
   
  double volume() const { return m_length * m_width * m_height; }
  double isSmallerThan(const Box& other) const { return volume() < other.volume(); }

private:
  double m_length, m_width, m_height;
};

int main()
{
  std::vector<Box> boxes{ {2.0, 2.0, 3.0}, {1.0, 3.0, 2.0}, {1.0, 2.0, 1.0}, {2.0, 3.0, 3.0} };

  // Step 1: create a view where begin() and end() are different.
  // The result of the take_while() range adapter has this property
  // (or, at least, it should have as per its specification in the Standard).
  auto first_boxes{ boxes | take_while([](const Box& box) { return box.volume() < 15; }) };
  
  /* This therefore generally does not compile... */
  //std::cout << "Volume of smallest box: " 
  //  << original_find_optimum(first_boxes.begin(), first_boxes.end(),
  //        [](const Box& box1, const Box& box2) { return box1.isSmallerThan(box2); })->volume()
  //  << std::endl;

  // Side-note: you can use the std::ranges::views::common to turn a range
  // where begin and end have a different type into a view where they do.
  auto common_boxes{ first_boxes | common };
  std::cout << "Volume of smallest box: " 
    << original_find_optimum(common_boxes.begin(), common_boxes.end(),
          [](const Box& box1, const Box& box2) { return box1.isSmallerThan(box2); })->volume()
    << std::endl;
  
  // Step 2: Show off our shiny new, modernised version of find_optimum()
  // First off: no need for the common adapter!
  std::cout << "Volume of largest box: "
    << find_optimum(first_boxes.begin(), first_boxes.end(),
          [](const Box& box1, const Box& box2) { return !box1.isSmallerThan(box2); })->volume()
    << std::endl;

  // Other cool features of our modern find_optimum() version include projection 
  // and the support for member function pointers. So no more lambdas required here!

  // Use a member-function pointer for the comparison function
  std::cout << "Volume of smallest box: " 
    << find_optimum(first_boxes.begin(), first_boxes.end(), &Box::isSmallerThan)->volume() 
    << std::endl;

  // Use a member-function pointer for the new projection functionality
  std::cout << "Volume of largest box: " 
    << find_optimum(first_boxes.begin(), first_boxes.end(), std::greater<>{}, &Box::volume)->volume()
    << std::endl;
}