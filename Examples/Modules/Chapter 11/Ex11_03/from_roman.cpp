// Implementation of the from_roman() function
module roman;

unsigned int from_roman(char c)
{
  switch (c)
  {
  case 'I': return 1;    case 'V': return 5;   case 'X': return 10;
  case 'L': return 50;   case 'C': return 100; case 'D': return 500;
  case 'M': return 1000; default:  return 0;
  }
}

unsigned int from_roman(std::string_view roman)
{
  unsigned int result{};
  for (size_t i{}, n{ roman.length() }; i < n; ++i)
  {
    const auto j{ from_roman(roman[i]) };   // Integer value of the i'th roman digit
    // Look at the next digit (if there is one) to know whether to add or subtract j
    if (i + 1 == n || j >= from_roman(roman[i + 1])) result += j; else result -= j;
  }
  return result;
}
