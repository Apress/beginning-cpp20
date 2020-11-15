// Throwing and catching standard exceptions
#include <iostream>
#include <stdexcept>
#include <vector>
#include <format>
#include <typeinfo>
#include <optional>

/*
  This solution triggers all exceptions mentioned in the text 
  accompanying the Table with all Standard Library exceptions, in order.
  To know how to trigger any other type, 
  you will have to consult your Standard Library reference.

  Note: while you'll typically catch exceptions by reference-to-const-std::exception 
  (unless more specific handling for concrete types is required, of course),
  we specify the concrete exception type instead here for clarity.
 */

// First, some dummy class types...
class BaseClass
{
public:
  virtual ~BaseClass() = default;
};

class DerivedClass1 : public BaseClass {};
class DerivedClass2 : public BaseClass {};

int main()
{
  try
  {
    std::vector v{ 1, 2, 3, 4, 5 };
    std::cout << v.at(10) << std::endl;
  }
  catch (const std::out_of_range& exception)
  {
    std::cout << "std::out_of_range: " << exception.what() << std::endl;
  }

  try
  {
    std::cout << std::format("Hello {:g}!\n", "World");
  }
  catch (const std::format_error& exception)
  {
    std::cout << "std::format_error: " << exception.what() << std::endl;
  }

  try
  {
    // Remember: a polymorphic class is a class with at least one virtual function.
    BaseClass* polymorphic{ nullptr };
    std::cout << typeid(*polymorphic).name();
  }
  catch (const std::bad_typeid& exception)
  {
    std::cout << "std::bad_typeid: " << exception.what() << std::endl;
  }

  try
  {
    DerivedClass1 derived;
    BaseClass& reference_to_base{ derived };
    dynamic_cast<DerivedClass2&>(reference_to_base);
  }
  catch (const std::bad_cast& exception)
  {
    std::cout << "std::bad_cast: " << exception.what() << std::endl;
  }

  try
  {
    std::optional<int> empty;
    std::cout << empty.value() << std::endl;
  }
  catch (const std::bad_optional_access& exception)
  {
    std::cout << "std::bad_optional_access: " << exception.what() << std::endl;
  }

  try
  {
    int size{ -1 };
    new int[size];
  }
  catch (const std::bad_alloc& exception)
  {
    std::cout << "std::bad_alloc: " << exception.what() << std::endl;
  }
}
