// Exercise 7-7
// Practice string concatenation, looping over strings, and stoi()-like functions
#include <iostream>
#include <string> 

int main()
{
  std::string numbers;
  
  std::cout << "Enter a sequence of numbers terminated by #:\n";
  
  while (true)
  {
    std::string number;         // Read strings one by one
    std::cin >> number;
    if (number == "#") break;   // Stop indefinite loop once "#" is encountered
    numbers += number + ' ';    // Concatenate all individual strings into one single string
  }

  long sum {};
  
  size_t index {};
  while (true)
  {
    const size_t found{ numbers.find(' ', index) }; // Search for the next space
    if (found == std::string::npos) break;          // Stop once we're at the end of the string
    const size_t length{ found - index };           // To access substrings, we need the length of the string
    const int i{ std::stoi(numbers.substr(index, length)) };
    sum += i;
    index += length + 1;                            // Increase the starting index (include the space)
  }
    
  std::cout << "The sum of the numbers you entered is: " << sum << std::endl;
  
  /*
  Note: another option would be a loop of the form
  
  for (size_t index {}; index < numbers.size(); )
  {
    // ... same as before, but the line that checks for npos and breaks can be omitted
  }
  */
}