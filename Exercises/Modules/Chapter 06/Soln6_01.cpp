// Exercise 6-1. Storing odd numbers in an array and accessing them using pointer notation

/* Note that the use of pointer notation is just for the sake of the exercise,           *
 * to help you understand the intimate relation between pointers and array names.        *
 * In real code, you'd normally just use array notation, because it is that much easier. */

#include <iostream>
#include <format>

int main()
{
  const size_t n {50};
  size_t odds[n];
  for (size_t i {}; i < n; ++i)
    odds[i] = i * 2 + 1;

  const size_t perline {10};
  std::cout << "The " << n << " first odd numbers are:\n";
  for (size_t i {}; i < n; ++i)
  {
    std::cout << std::format("{:5}", *(odds + i));
    if ((i + 1) % perline == 0)                        // Uses the loop counter to decide when a newline is required
      std::cout << std::endl;
  }

  std::cout << "\nIn reverse order these numbers are:\n";
  for (int i {n - 1}; i >= 0; --i)                     // This won't work with size_t for the loop counter
  {                                                    // because size_t cannot be negative
    std::cout << std::format("{:5}", *(odds + i));
    if (i % perline == 0)
      std::cout << std::endl;
  }
}