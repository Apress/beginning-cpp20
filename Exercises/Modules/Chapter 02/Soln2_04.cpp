// Exercise 2-4. Calculating the Body Mass Index.
// In the expression for bmi, both h_feet and h_inches will be implicitly converted to double
// because the other operand of the sub-expression is double.

import <iostream>;

int main()
{
  const double lbs_per_kg {2.2};
  const double inches_per_foot {12.0};
  const double meters_per_foot {0.3048};
  
  double w_lbs {};
  unsigned int h_feet {};
  unsigned int h_inches {};

  std::cout << "Enter your weight in pounds: ";
  std::cin >> w_lbs;
  std::cout << "Enter you height in feet and inches: ";
  std::cin >> h_feet >> h_inches;

  const double w_kg {w_lbs / lbs_per_kg};
  const double h_meters { meters_per_foot * h_feet + h_inches / inches_per_foot };
  const double bmi {w_kg / (h_meters * h_meters)};
  std::cout << "Your BMI is " << bmi << std::endl;
}