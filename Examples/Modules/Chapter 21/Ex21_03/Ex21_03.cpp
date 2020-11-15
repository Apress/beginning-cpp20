// Violating constraints of uninstantiated class members
#include "Array.h"
#include <memory>  // For std::unique_ptr<>

// Assert that Array<std::unique_ptr<int>> is a valid type
static_assert(requires { typename Array<std::unique_ptr<int>>; });

int main()
{
  Array<std::unique_ptr<int>> tenSmartPointers(10);
  Array<std::unique_ptr<int>> target;
  // target = tenSmartPointers;   /* Constraint not satisfied: copyable<unique_ptr> */
  target = std::move(tenSmartPointers);
  target.push_back(std::make_unique<int>(123));
}
