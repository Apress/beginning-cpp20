// Exercise 6-4. Storing numbers in a vector

/*
 * The result is an approximate value for pi. 
 * The more values you use, the closer it becomes to pi.
 * In technical speak, this approximation does not converge to pi very fast though,
 * which basically means that you'll need quite some values 
 * if you want to approximate pi beyond its first few digits.
 *
 * We must dereference values to use it with the subscript operator
 * because it is not a vector but a pointer to a vector.
 * 
 * Note that allocating a vector<> like this in the free store is not often done.
 * Dynamic allocation is mostly reserved for objects of other class types,
 * in particular polymorphic ones. You'll learn all about this in later chapters!
 */

import <iostream>;
import <format>;
import <vector>;

#include <cmath>

int main()
{
  size_t n {};
  std::cout << "Enter the number of vector elements: ";
  std::cin >> n;
  auto* values{ new std::vector<double>(n) };

  for (size_t i {}; i < n; ++i)
    (*values)[i] = 1.0 / ((i + 1)*(i + 1));
  
  double sum {};
  for (auto value : *values)
    sum += value;

  std::cout << std::format("Result is {}", std::sqrt(6.0*sum)) << std::endl;
  
  delete values;                                              // It's not an array this time!
}