// Exercise 20-14: the hard nut
#include <iostream>
#include <algorithm>
#include <ranges>
#include <iterator>
#include <cmath>

using namespace std::ranges::views;

bool isPrime(unsigned number)
{
  return number >= 2 
      && std::ranges::none_of(
           iota(2u, static_cast<unsigned>(std::sqrt(number) + 1)),
           [number](unsigned divisor) { return number % divisor == 0; }
         );
}

int main()
{
  // This first version is one that compiled (with some help) on at least one compiler.
  // It uses one thing you have not encountered yet: std::ranges::views::common.
  // This range adaptor transforms a given range into a view where begin() and end()
  // return values of the same type, something which in general is not true for ranges. 
  // Legacy algorithms, such as the iterator-pair-based std::copy() algorithm, 
  // often expect iterator pairs to have the same type, though.
  auto view { 
    std::ranges::istream_view<int>(std::cin)
      | take_while([](int i) { return i >= 0; })
      | transform([](int i) { return static_cast<unsigned>(i); })
      | filter(isPrime)
      | transform([](unsigned i) { return "Yes, that is a prime!"; })
      | common 
  };

  std::copy(view.begin(), view.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

/*
  // Same as the previous one, but then without the legacy iterator-pair-based copy()
  // (and thus without the common range adaptor).
  // At the time we tried this, this did not compile yet in any compiler.
  auto view {
    std::ranges::istream_view<int>(std::cin)
      | take_while([](int i) { return i >= 0; })
      | transform([](int i) { return static_cast<unsigned>(i); })
      | filter(isPrime)
      | transform([](unsigned i) { return "Yes, that is a prime!"; })
  };

  std::ranges::copy(view, std::ostream_iterator<std::string>(std::cout, "\n"));
*/

/*
  // A variation that uses std::ranges::for_each(). 
  // But, like the exercise says, this is cheating though, 
  // as for_each() is just a poorly disguised range-based for loop,
  // and loops were not allowed!
  std::ranges::for_each(
    std::ranges::istream_view<int>(std::cin)
      | take_while([](int i) { return i >= 0; })
      | transform([](int i) { return static_cast<unsigned>(i); })
      | filter(isPrime)
      | transform([](unsigned i) { return "Yes, that is a prime!"; })
    , [](const auto& s) { std::cout << s << std::endl; }
  );
*/

/*
  // A "clever" version where we print during a filter step
  auto view {
    std::ranges::istream_view<int>(std::cin)
      | take_while([](int i) { return i >= 0; })
      | transform([](int i) { return static_cast<unsigned>(i); })
      | filter(isPrime)
      | filter([](unsigned i) { std::cout << "Yes, that is a prime!\n"; return false; })
  };
  view.begin(); // Try to find the begin of the view
                // Since the last step filters out all elements, though,
                // this will never find a begin, and eventually return view.end()...
*/
}