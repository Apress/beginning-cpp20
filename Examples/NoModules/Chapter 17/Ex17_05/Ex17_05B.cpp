// Disambiguating dependant names
// Note: not all compilers may implement the C++20 rules already,
// any may still require additional typename keywords in front of T::Derived

template <typename T>
class Outer
{
public:
  class Nested { /* ... */ };  // Or a type alias of form 'using Nested = ...;'
  // ...
};

template <typename T>   // T assumed to define nested Base and Derived types / aliases
void someOtherFunction()
{
  typename T::Base* b{ new T::Derived{} };                      // Or: auto* b{ ... }
  const typename T::Derived& d{ static_cast<T::Derived&>(*b) }; // Or: const auto& d{ ... }
  /* ... */
}
