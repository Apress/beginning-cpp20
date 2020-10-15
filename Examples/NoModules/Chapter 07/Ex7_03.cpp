// Comparing strings
#include <iostream>    // For stream I/O
#include <format>      // For string formatting
#include <string>      // For the string type
#include <vector>      // For the vector container

int main()
{
  std::vector<std::string> names;     // Vector of names
  std::string input_name;             // Stores a name

  for (;;)                            // Indefinite loop (stopped using break)
  {
    std::cout << "Enter a name followed by Enter (leave blank to stop): ";
    std::getline(std::cin, input_name);  // Read a name and...
    if (input_name.empty()) break;       // ...if it's not empty...
    names.push_back(input_name);         // ...add it to the vector
  }

  // Sort the names in ascending sequence
  bool sorted {};                      
  do
  {
    sorted = true;                // remains true when names are sorted
    for (size_t i {1}; i < names.size(); ++i)
    {
      if (names[i-1] > names[i])
      { // Out of order - so swap names
        names[i].swap(names[i-1]);
        sorted = false;
      }
    }
  } while (!sorted);

  // Find the length of the longest name
  size_t max_length{};
  for (const auto& name : names)
    if (max_length < name.length())
      max_length = name.length();

  // Output the sorted names 5 to a line
  const size_t field_width{ max_length + 2 };
  size_t count {};

  std::cout << "In ascending sequence the names you entered are:\n";
  for (const auto& name : names)
  {
    std::cout << std::format("{:>{}}", name, field_width); // Right-align + dynamic width
    if (!(++count % 5)) std::cout << std::endl;
  }

  std::cout << std::endl;
}
