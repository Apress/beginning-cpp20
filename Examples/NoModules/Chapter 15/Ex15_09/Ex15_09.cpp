// Using the typeid() operator
#include <iostream>
#include <typeinfo>         // For the std::type_info class
#include "Box.h"
#include "Carton.h"

// Define trivial non-polymorphic base and derived classes:
class NonPolyBase {};
class NonPolyDerived : public NonPolyBase {};

Box& getSomeBox();              // Function returning a reference to a polymorphic type
NonPolyBase& getSomeNonPoly();  // Function returning a reference to a non-polymorphic type

int main()
{
  // Part 1: typeid() on types and == operator
  std::cout << "Type double has name " << typeid(double).name() << std::endl;
  std::cout << "1 is " << (typeid(1) == typeid(int)? "an int" : "no int") << std::endl;

  // Part 2: typeid() on polymorphic references
  Carton carton{ 1, 2, 3, "paperboard" };
  Box& boxReference{ carton };

  std::cout << "Type of carton is "       << typeid(carton).name()       << std::endl;
  std::cout << "Type of boxReference is " << typeid(boxReference).name() << std::endl;
  std::cout << "These are " << (typeid(carton) == typeid(boxReference)? "" : "not ")
            << "equal" << std::endl;

  // Part 3: typeid() on polymorphic pointers
  Box* boxPointer{ &carton };
  std::cout << "Type of &carton is "     << typeid(&carton).name()     << std::endl;
  std::cout << "Type of boxPointer is "  << typeid(boxPointer).name()  << std::endl;
  std::cout << "Type of *boxPointer is " << typeid(*boxPointer).name() << std::endl;

  // Part 4: typeid() with non-polymorphic classes
  NonPolyDerived derived;
  NonPolyBase& baseRef{ derived };

  std::cout << "Type of baseRef is " << typeid(baseRef).name() << std::endl;

  // Part 5: typeid() on expressions
  const auto& type_info1{ typeid(getSomeBox()) };       // function call evaluated
  const auto& type_info2{ typeid(getSomeNonPoly()) };   // function call not evaluated
  std::cout << "Type of getSomeBox() is " << type_info1.name() << std::endl;
  std::cout << "Type of getSomeNonPoly() is "    << type_info2.name() << std::endl;
}

Box& getSomeBox()
{
  std::cout << "getSomeBox() called..." << std::endl;
  static Carton carton{ 2, 3, 5, "duplex" };
  return carton;
}
NonPolyBase& getSomeNonPoly()
{
  std::cout << "getSomeNonPoly() called..." << std::endl;
  static NonPolyDerived derived;
  return derived;
}
