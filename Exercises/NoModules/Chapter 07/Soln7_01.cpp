// Exercise 7-1 Storing student names and grades. 
// This uses a vector of string objects to store the names.
#include <iostream>
#include <format>
#include <cctype>
#include <vector>
#include <string>

int main()
{
  std::vector<std::string> names;
  std::vector<double> grades;
  
  size_t max_length {};        // Longest name length
  double average_grade {};     // First accumulates the sum of the grades, 
                               // to be divided by the number of grades later
  // Data entry loop. 
  // This loop reads the name and grade for each student.
  while (true)
  {
    std::cout << "Enter a student's name: ";
    std::string name;                       // Stores a student name
    std::getline(std::cin, name);

    names.push_back(name);
    
    if (max_length < name.length()) 
        max_length = name.length();

    std::cout << "Enter " << name << "\'s grade: ";
    double grade {};                        // Stores a student grade
    std::cin >> grade;
    grades.push_back(grade);

    average_grade += grade;

    std::cout << "Do you wish to enter another student's details (y/n): ";
    char answer {};
    std::cin >> answer;
    
    // Ignore the line break that is still on the input stream after reading the y/n character
    // Otherwise the next std::getline() always returns an empty line...
    // (Note: we'll try to remember to add this annoyance as a hint in the next edition...)
    std::cin.ignore();
    
    if (std::toupper(answer) == 'N') break;
  } 

  // Calculating the class average.
  average_grade /= grades.size();

  // Displaying the class average.
  std::cout << 
    std::format("\nThe class average for {} students is {:.2f}\n", names.size(), average_grade);

  // Displaying the students' names and grades.
  const size_t perline {3};
  for (size_t i {}; i < names.size(); ++i)
  {
    std::cout << std::format("{:<{}} {:>4}\t", names[i], max_length, grades[i]);
    if ((i + 1) % perline) continue;
    std::cout << std::endl;
  }
  std::cout << std::endl;
}