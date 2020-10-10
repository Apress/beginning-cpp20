// Implementing add(), subtract() and multiply() 
#include <iostream>
#include "Integer.h"

/***********************************************************
 By returning the dereferenced this pointer in the functions
 we can call the functions successively in a single statement.
 Note the parameter is a reference-to-const;
 const because the argument is not changed by the function
 and a reference to avoid the overhead of copying objects.
 The only other requirement for achieving the calculation
 in a single statement is figuring out how to sequence to
 operations to allow this.
 ***********************************************************/

int main()
{
  // Create the even operands as Integers, 
  // and use implicit conversions from int for the odd values
  const Integer four{4};
  const Integer six{6};
  const Integer eight{8};
  
  // We can calculate 4*5*5*5+6*5*5+7*5+8 as:
  //     ((4*5+6)*5+7)*5+8
  Integer result {four};                       // Set result object as copy of four
  std::cout << "Result is "
            << result.multiply(5).add(six).multiply(5).add(7).multiply(5).add(eight).getValue()
            << std::endl;
}