// Exercise A-3   Writing an exception class that records where 
// the exception object was thrown (or at least, where it was created).
#include <iostream>
#include "SmartException.h"

int main()
{
  try
  {
    throw SmartException{ "Throwing directly..." };
  }
  catch (const SmartException& exception)
  {
    std::cerr << "Something went wrong at line " << exception.where().line() << std::endl;
  }

  // Advanced use. This was no requirement of the exercise, 
  // but it seems like something a smart exception could use...
  try
  {
    SmartException exception{ "Throwing later...", {} };
    // ...
    exception.throwFromHere();
  }
  catch (const SmartException& exception)
  {
    std::cerr << "Something went wrong at line " << exception.where().line() << std::endl;
  }
}