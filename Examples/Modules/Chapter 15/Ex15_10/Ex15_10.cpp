// Using the typeid() operator
import <print>;
import <typeinfo>;         // For the std::type_info class
import boxes;

// Define trivial non-polymorphic base and derived classes:
class NonPolyBase {};
class NonPolyDerived : public NonPolyBase {};

Box& getSomeBox();              // Function returning a reference to a polymorphic type
NonPolyBase& getSomeNonPoly();  // Function returning a reference to a non-polymorphic type

int main()
{
  // Part 1: typeid() on types and == operator
  std::println("Type double has name {}", typeid(double).name());
  std::println("1 is {}", typeid(1) == typeid(int)? "an int" : "no int");

  // Part 2: typeid() on polymorphic references
  Carton carton{ 1, 2, 3, "paperboard" };
  Box& boxReference = carton;

  std::println("Type of carton is {}", typeid(carton).name());
  std::println("Type of boxReference is {}", typeid(boxReference).name());
  std::println("These are{} equal", typeid(carton) == typeid(boxReference) ? "" : "not");

  // Part 3: typeid() on polymorphic pointers
  Box* boxPointer = &carton;
  std::println("Type of &carton is {}", typeid(&carton).name());
  std::println("Type of boxPointer is {}", typeid(boxPointer).name());
  std::println("Type of *boxPointer is {}", typeid(*boxPointer).name());

  // Part 4: typeid() with non-polymorphic classes
  NonPolyDerived derived;
  NonPolyBase& baseRef = derived;

  std::println("Type of baseRef is {}", typeid(baseRef).name());

  // Part 5: typeid() on expressions
  const auto& type_info1 = typeid(getSomeBox());       // function call evaluated
  const auto& type_info2 = typeid(getSomeNonPoly());   // function call not evaluated
  std::println("Type of getSomeBox() is {}", type_info1.name());
  std::println("Type of getSomeNonPoly() is {}", type_info2.name());
}

Box& getSomeBox()
{
  std::println("getSomeBox() called...");
  static Carton carton{ 2, 3, 5, "duplex" };
  return carton;
}
NonPolyBase& getSomeNonPoly()
{
  std::println("getSomeNonPoly() called...");
  static NonPolyDerived derived;
  return derived;
}
