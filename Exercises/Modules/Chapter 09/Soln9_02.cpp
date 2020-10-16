// Exercise 9-2 Working with std::string_view<> and std::span<>
#include <iostream>
#include <format>
#include <string_view>
#include <span>

// The function prototype including defaults for parameters
void show_data(
  std::span<const int> data,
  std::string_view title = "Data Values",
  size_t width = 10, size_t perLine = 5);

// Extra overload to output a single value (.
void show_data(
  int data,
  std::string_view title = "Data Values",
  size_t width = 10);

int main()
{
  int samples[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

  int dataItem{ -99 };
  show_data({ &dataItem, 1 });  // Call original function directly

  dataItem = 13;
  show_data(dataItem, "Unlucky for some!"); // Use extra overload

  show_data(samples);
  show_data(samples, "Samples");
  show_data(samples, "Samples", 6);
  show_data(samples, "Samples", 8, 4);
}

void show_data(
  std::span<const int> data, 
  std::string_view title,
  size_t width, size_t perLine)
{
  std::cout << title << std::endl;    // Display the title

  // Output the data values
  for (size_t i{}; i < data.size(); ++i)
  {
    std::cout << std::format("{:{}}", data[i], width); // Display a data item
    if ((i + 1) % perLine == 0)                        // Newline after perLine values
      std::cout << '\n';
  }
  std::cout << std::endl;
}

void show_data(int data, std::string_view title, size_t width)
{
  show_data({ &data, 1 }, title, width);
}
