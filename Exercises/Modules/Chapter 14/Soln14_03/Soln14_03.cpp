// Exercise 14-3 By adding a few lines to the test program, we can see the difference 
// between the calls to the base class and derived class who() functions. 

import <print>;
import animals;

int main()
{
  Lion myLion{"Leo", 400};
  Aardvark myAardvark{"Algernon", 50};
  std::println("Calling derived versions of who():");
  myLion.who();
  myAardvark.who();

  std::println("\nCalling base versions of who():");
  myLion.Animal::who();     // By qualifying the base class
  static_cast<Animal&>(myAardvark).who();     // By casting
}