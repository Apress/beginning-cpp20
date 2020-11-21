// Exercise 14-1 Exercising the Animal classes
// The solution shows two options, with the second one being the preferred option.
#include "Animals.h"

int main()
{
  Lion myLion{"Leo", 400};
  Aardvark myAardvark{"Algernon", 50};
  myLion.who();
  myAardvark.who();
}