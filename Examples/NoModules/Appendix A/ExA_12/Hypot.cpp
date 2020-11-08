// Hypot.cpp - Definition of the math::hypot() function
#include "ProperMath.h"  // For the square() function template definition
#include "Hypot.h"       // Missing from the code listing in the book!
#include <cmath>         // For std::sqrt()

// Caution: See Chapter 11 for why you should always use std::hypot() 
// over this naïve definition (based on the Pythagorean Theorem)!
double math::hypot(double x, double y) { return std::sqrt(square(x) + square(y)); }
