// Exercise 21-1  Understanding compound and simple requirements
#include <concepts>    // For the std::same_as<> and std::convertible_to<> concepts
#include <ranges>      // For std::ranges::range<> concept
#include <type_traits> // For the std::remove_cv<> type trait
#include <list>
#include <vector>
#include <string>

template <typename Iter>
concept BidirectionalIterator = true; // Feel free to further work out all requirements...

// A compound requirement "{ expr } -> concept<Args>;" is equivalent to 
// the simple requirement "expr;", 
// combined with the nested requirement "requires concept<decltype(expr),Args>;"
template<class Iter>
concept RandomAccessIterator = BidirectionalIterator<Iter>
  && requires(const Iter i, const Iter j, Iter k, const int n)
     {
       { i - n }; { i + n }; { n + i };
       requires std::same_as<decltype(i - n), Iter>;
       requires std::same_as<decltype(i + n), Iter>;
       requires std::same_as<decltype(n + i), Iter>;
       { k += n }; { k -= n };
       requires std::same_as<decltype(k += n), Iter&>;
       requires std::same_as<decltype(k -= n), Iter&>;
       i[n];
       requires std::same_as<decltype(i[n]), decltype(*i)>;
       i < j; i > j; i <= j; i >= j;
       requires std::convertible_to<decltype(i < j), bool>
             && std::convertible_to<decltype(i > j), bool>
             && std::convertible_to<decltype(i <= j), bool>
             && std::convertible_to<decltype(i >= j), bool>;
     };

// To rewrite a compound requirement with noexcept you should know 
// that noexcept(expr) is a valid constant expression as well...
template <typename T>
concept NoExceptDestructible = requires (T& value) 
{ 
  value.~T();
  noexcept(value.~T());
};

template <typename C>
concept Character = std::same_as<std::remove_cv_t<C>, char>
                  || std::same_as<std::remove_cv_t<C>, char8_t>
                  || std::same_as<std::remove_cv_t<C>, char16_t>
                  || std::same_as<std::remove_cv_t<C>, char32_t>
                  || std::same_as<std::remove_cv_t<C>, wchar_t>;

// More of the same...
template <typename S>
concept String = std::ranges::range<S> && requires(S & s, const S & cs)
{
  typename S::value_type;
  requires Character<typename S::value_type>;
  cs.length();
  requires std::integral<decltype(cs.length())>;
  s[0]; cs[0];
  requires std::same_as<decltype(s[0]), typename S::value_type&>
        && std::convertible_to<decltype(cs[0]), typename S::value_type>;
  s.data(); cs.data();
  requires std::same_as<decltype(s.data()), typename S::value_type*>
        && std::same_as<decltype(cs.data()), const typename S::value_type*>;
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