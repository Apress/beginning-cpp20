// Disambiguating dependant names

// Note: not all compilers may implement the C++20 rules already,
// any may still require additional typename keywords in front of Outer<T>::Nested

template <typename T>
class Outer
{
public:
  class Nested { /* ... */ };  // Or a type alias of form 'using Nested = ...;'
  // ...
};

template <typename T>
class MyClass
{
public:
  Outer<T>::Nested memberFunction(const Outer<T>::Nested& nested);
private:
  T::Nested m_member_variable;
};

template<class T>
T::Nested nonMemberFunction(const typename T::Nested* nested);

template<typename T>
Outer<T>::Nested MyClass<T>::memberFunction(const typename Outer<T>::Nested& nested)
{
  return nested;
}
