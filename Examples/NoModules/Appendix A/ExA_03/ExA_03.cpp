// Using std::source_location, C++'s answer to __LINE__ and __FILE__
#include <iostream>
#include <source_location>
#include <string_view>
#include <format>

void logError(std::string_view message,
              std::source_location location = std::source_location::current())
{
  std::cerr << std::format("{}:{}:{} - An unexpected error occurred in {}: {}",
    location.file_name(), location.line(), location.column(),
    location.function_name(), message) << std::endl;
}

int main() 
{ 
  logError("OOPS!");  // The line number in the log message will refer to 
                      // this line in main(), not to the where logError() is defined.
}