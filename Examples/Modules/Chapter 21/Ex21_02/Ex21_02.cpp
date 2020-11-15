// Asserting that a type models a concept
#include <concepts>    // For the std::same_as<> and std::convertible_to<> concepts
#include <ranges>      // For std::ranges::range<> concept
#include <type_traits> // For the std::remove_cv<> type trait
#include <list>
#include <vector>
#include <string>

template <typename Iter>
concept BidirectionalIterator = true; // Feel free to further work out all requirements...

template<class Iter>
concept RandomAccessIterator = BidirectionalIterator<Iter>
  && requires(const Iter i, const Iter j, Iter k, const int n)
     {
       { i - n } -> std::same_as<Iter>;
       { i + n } -> std::same_as<Iter>; { n + i } -> std::same_as<Iter>;
       { k += n }-> std::same_as<Iter&>; { k -= n }-> std::same_as<Iter&>;
       { i[n] }  -> std::same_as<decltype(*i)>;
       { i < j } -> std::convertible_to<bool>;
       { i > j } -> std::convertible_to<bool>;
       { i <= j } -> std::convertible_to<bool>;
       { i >= j } -> std::convertible_to<bool>;
     };

template <typename T>
concept NoExceptDestructible = requires (T & value) { { value.~T() } noexcept; };

template <typename C>
concept Character = std::same_as<std::remove_cv_t<C>, char>
                  || std::same_as<std::remove_cv_t<C>, char8_t>
                  || std::same_as<std::remove_cv_t<C>, char16_t>
                  || std::same_as<std::remove_cv_t<C>, char32_t>
                  || std::same_as<std::remove_cv_t<C>, wchar_t>;

template <typename S>
concept String = std::ranges::range<S> && requires(S & s, const S & cs)
{
  typename S::value_type;
  requires Character<typename S::value_type>;
  { cs.length() } -> std::integral;
  { s[0] } -> std::same_as<typename S::value_type&>;
  { cs[0] } -> std::convertible_to<typename S::value_type>;
  { s.data() } -> std::same_as<typename S::value_type*>;
  { cs.data() } -> std::same_as<const typename S::value_type*>;
  // ...
};

static_assert(NoExceptDestructible<std::string>);
static_assert(NoExceptDestructible<int>);
static_assert(String<std::string>);
static_assert(!String<std::vector<char>>);
static_assert(Character<char>);
static_assert(Character<const char>);
static_assert(RandomAccessIterator<std::vector<int>::iterator>);
static_assert(!RandomAccessIterator<std::list<int>::iterator>);
static_assert(RandomAccessIterator<int*>);

int main()
{
}