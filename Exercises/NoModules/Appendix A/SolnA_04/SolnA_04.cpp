// Exercise A-4   Defining class member functions in the header
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
    SmartException exception{ "Throwing later...", {} };  // Optional: {} to avoid calling std::source_location::current()
    // ...
    exception.throwFromHere();
  }
  catch (const SmartException& exception)
  {
    std::cerr << "Something went wrong at line " << exception.where().line() << std::endl;
  }
}