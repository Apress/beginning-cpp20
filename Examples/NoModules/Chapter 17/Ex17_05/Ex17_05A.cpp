// Disambiguating dependant names: this code will not compile. 

// Uncomment the typename keyword to turn Outer<T>::Nested into 
// a dependent type name and fix the compilation
template <typename T>
void someFunction() { /*typename*/ Outer<T>::Nested* nested; /* ... */ }
