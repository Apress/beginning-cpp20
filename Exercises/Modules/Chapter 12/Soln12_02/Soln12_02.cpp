// Using a function with a reference parameter in the Integer class
import <iostream>;
import integer;

/*****************************************************************\
 Using the version of compare() with the pass-by-value parameter,
 the copy constructor is called because a copy of the argument
 is passed to the function.

 Using the version with the reference parameter a reference
 to the object is passed to the function so no constructor call
 is necessary.

 You cannot overload a function with a reference parameter with
 a function that has a non-reference parameter because the
 compiler cannot tell which function should be called in any
 particular instance.
\*****************************************************************/

int main()
{
  std::cout << "Create i with the value 0." << std::endl;
  Integer i;
  i.show();
  std::cout << "Change value  of i to 15." << std::endl;
  i.setValue(15);
  i.show();
 
  std::cout << "Create j from object i." << std::endl;
  Integer j {i};
  j.show();
  std::cout << "Set value of j to 150 times that of i." << std::endl;
  j.setValue(150 * i.getValue());
  j.show();

  std::cout << "Create k with the value 789." << std::endl;
  Integer k {789};
  k.show();
  std::cout << "Set value of k to sum of i and j values." << std::endl;
  k.setValue(i.getValue() + j.getValue());
  k.show();

  std::cout << "Result of comparing i and j is " << i.compare(j) << std::endl;
  std::cout << "Result of comparing k and j is " << k.compare(j) << std::endl;
}