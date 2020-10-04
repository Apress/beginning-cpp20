// Exercise 5-4 Print out characters entered by the user in reverse order
#include <iostream>

int main()
{
  const size_t max_num_characters {1'000};
  char string[max_num_characters];

  std::cout << "Please enter a string: ";
  std::cin.getline(string, max_num_characters);
  
  // Count the number of characters
  size_t count {};
  for (; count < max_num_characters && string[count] != '\0'; ++count) {}

/*
  Take care: never write the following:
    for (size_t i = count - 1; i >= 0; --i)
      ...
  Because size_t is unsigned, the loop continuation condition i >= 0 
  shall always and forever be true. That is: every size_t value is always greater or equal to zero, 
  by definition. Subtracting one from zero wraps around to std::numeric_limits<size_t>::max(), 
  a huge number.
  
  Other solutions besides the one we use below include:
    // Cast to a signed integer (works even for count == 0!)
	for (size_t i = count - 1; static_cast<signed>(i) != -1; --i)
	  ...
    
	// Subtract in second for expression (less readable, fails if count == 0)
    for (size_t i = count; i-- > 0; )
	  ...
  
    // Use a break statement to end the loop (fails if count == 0)
	for (size_t i = count; ; i--)
	{
	  ...
      if (i == 0) break;
	}
*/

  // Print out the characters in reverse order
  for (size_t i = 1; i <= count; ++i)
  {
    std::cout << string[count - i];
  }
  std::cout << std::endl;
}