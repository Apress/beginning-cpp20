// Exercise 8-1 Reading  and validating a date of birth. 
// As always, there are many ways of doing this!
#include <iostream>
#include <format>
#include <string>

int validate_input(int lower, int upper, const std::string& description);
int year();
int month();
int date(int month_value, int year_value);
std::string ending(int date_day);

int main()
{
  std::cout << "Enter your date of birth." << std::endl;
  int date_year {year()};
  int date_month {month()};
  int date_day {date(date_month, date_year)};

  std::string months[]  {"January", "February", "March", "April", "May", "June", "July",
                         "August", "September", "October", "November", "December"  };

  std::cout << std::endl;
  std::cout << 
    std::format("You were born on the {} of {}, {}.", 
      std::to_string(date_day) + ending(date_day), 
      months[date_month - 1], 
      date_year
    ) << std::endl;
}

// Reads an integer that is between lower and upper inclusive
int validate_input(int lower, int upper, const std::string& description)
{
  int data {};
  std::cout << std::format("Please enter {} from {} to {}: ", description, lower, upper);
  std::cin >> data;
  while (data < lower || data > upper)
  {
    std::cout << "Invalid entry; please re-enter " << description << ": ";
    std::cin >> data;
  }
  return data;
}

// Reads the year
int year()
{
  const int low_year {1870};         // Program only works for folks under 150 years old 
  const int high_year {2020};        // and those already born...
  return validate_input(low_year, high_year, "a year");
}

// Reads the month
int month()
{
  const int low_month {1};
  const int high_month {12};
  return validate_input(low_month, high_month, "a month number");
}

// Reads in the date in the given month and year
int date(int month_number, int year)
{
  const int date_min {1};
  const int feb {2};

  // Days in month:            Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
  static const int date_max[]  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  // With the above array declared as static, it will only be created the first
  // time the function is called. Of course, this doesn't save anything in this 
  // example as we only call it once...

  // Feb has 29 days in a leap year. A leap year is a year that is divible by 4
  // except years that are divisible by 100 but not divisible by 400
  if (month_number == feb && year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0))
    return validate_input(date_min, 29, "a date");
  else
    return validate_input(date_min, date_max[month_number - 1], "a date");
}

// Select the ending of the ordinal day number
std::string ending(int date_day)
{
  if (date_day == 1 || date_day == 21 || date_day == 31)
    return "st";
  else if (date_day == 2 || date_day == 22)
    return "nd";
  else if (date_day == 3 || date_day == 23)
    return "rd";
  else
    return "th";
}