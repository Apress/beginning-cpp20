// Disambiguating dependant base class names
// (this code does not compile without changes)

import <iostream>;

template <typename T>
class Base
{
public:
  void baseFun() { /* ... */ }
protected:
  int m_base_var {};
};

template <typename T>
class Derived : public Base<T>
{
public:
  void derivedFun();

  // Option 3: using declarations (remove to see error messages)
// using Base<T>::baseFun;
// using Base<T>::m_base_var;
};

template <typename T>
void Derived<T>::derivedFun()
{
  // These two lines should give compiler errors.
  // Uncomment the using declarations in the Derived<> template 
  // to make them work. Alternative solutions are illustrated below.
  baseFun();
  std::cout << m_base_var << std::endl;

  // Option 1: add this->
  this->baseFun();
  std::cout << this->m_base_var << std::endl;

  // Option 2: add Base<T>::
  Base<T>::baseFun();
  std::cout << Base<T>::m_base_var << std::endl;
}

int main()
{
}

