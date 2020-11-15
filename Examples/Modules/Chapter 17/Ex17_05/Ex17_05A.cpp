// Disambiguating dependant names: this code will not compile. 

template <typename T>
class Outer
{
public:
  class Nested { /* ... */ };  // Or a type alias of form 'using Nested = ...;'
  // ...
};

// Uncomment the typename keyword to turn Outer<T>::Nested into 
// a dependent type name and fix the compilation
template <typename T>
void someFunction() { /*typename*/ Outer<T>::Nested* nested; /* ... */ }
