// Exercise 21-4  Generalising medianOfSorted()
import <iostream>;
import <concepts>;
import <array>;
import <string>;
import <vector>;
import <list>;
import <forward_list>;
import <span>;
import <ranges>;
import <iterator>;

/*
  Apologies. When we wrote the exercise, we misread what a std::sized_range() was.
  std::sized_range() is no concept for statically fixed-size ranges, 
  but for ranges for which std::ranges::size() may be invoked *at runtime*.
  So this solution presents the next best thing: a medianOfSorted() that works
  for any range (not just fixed-size ranges), with appropriate type constraints.
  Key point is that underlying, range-based algorithms still very much work with iterators.
  Most requirements use Standard Library concepts in the std::ranges namespace,
  and the function implementations use Standard Library functions in that same namespace.
 */

/* Not requested, but just for fun, here is a concept that prescribes 
   a complete set of operations one would require to take an average */
template <typename T>
concept Averagable = requires (const T x, const T y, T z, const int i)
{
  { x + y }  -> std::same_as<T>;
  { x - y }  -> std::same_as<T>;
  { z += y } -> std::same_as<T&>;
  { z -= y } -> std::same_as<T&>;
  { x / i }  -> std::same_as<T>;
  { x * i }  -> std::same_as<T>;
  { z /= i } -> std::same_as<T&>;
  { z *= i } -> std::same_as<T&>;
};

// By default, take the N/2'th element
template <std::ranges::sized_range Range>   // Requires being able to determine the range's size using std::ranges::size()
  requires std::ranges::input_range<Range>  // Requires being able to dereference an iterator over the range.
auto& medianOfSorted(Range&& range)
{
  auto iter{ std::ranges::begin(range) };   // Supported for every range
  std::ranges::advance(iter, std::ranges::size(range) / 2);  // Advances in constant time for random-access ranges, linearly otherwise.
  return *iter;                             // Only possible with input iterators...
}

// When we can take an average, check the size 
// (dynamically, not statically as was the original intent) 
// to decide whether we need to do so...
template <std::ranges::sized_range Range> 
  requires std::ranges::forward_range<Range>  // More strict than before: we need the multi-pass guarantee
        && Averagable<std::ranges::range_value_t<Range>>
auto medianOfSorted(Range&& range)
{
  const auto N{ std::ranges::size(range) };
  auto iter{ std::ranges::begin(range) };
  if (N % 2 == 0)
  {
    std::ranges::advance(iter, N / 2 - 1);
    const auto& value1{ *iter };      // Reference remains valid because iter is a forward iterator!
    std::ranges::advance(iter, 1);
    return (value1 + *iter) / 2;
  }
  else
  {
    std::ranges::advance(iter, N / 2);
    return *iter;
  }
}

int main()
{
  std::array values_odd{ 1, 2, 3, 4, 5, 6, 7 };
  std::cout << medianOfSorted(values_odd) << std::endl;

  std::array values_even{ 1., 2., 3., 4., 5., 6. };
  std::cout << medianOfSorted(values_even) << std::endl;

  std::string strings_odd[] { "1", "2", "3", "4", "5" };
  std::cout << medianOfSorted(strings_odd) << std::endl;

  std::string strings_even[] { "1", "2", "3", "4", "5", "6" };
  std::cout << medianOfSorted(std::span{ strings_even }) << std::endl;

  std::vector dynamically_sized{ 1.f, 2.f, 3.f, 4.f };
  std::cout << medianOfSorted(dynamically_sized) << std::endl;

  std::list non_random_access{ 4.f, 3.f, 2.f, 1.f, 0.f };
  std::cout << medianOfSorted(non_random_access) << std::endl;

  std::forward_list non_sized_ranged{ 123, 456, 789 };
  //std::cout << medianOfSorted(non_sized_ranged) << std::endl; /* Error: not sized! */
}