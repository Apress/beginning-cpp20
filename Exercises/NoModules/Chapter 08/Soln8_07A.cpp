// Exercise 8-7 Computing Fibinacci numbers iteratively. 
// On most systems (it depends on sizeof(unsigned long long)),
// you can correctly compute up to 93 Fibonacci numbers with this program.
#include <iostream>

unsigned long long fib(size_t n);

int main()
{
  size_t num{};
  std::cout << "Good day, master. How many Fibonacci numbers shall I compute today?" << std::endl;
  std::cin >> num;
  
  for (size_t i{1}; i <= num; ++i)
     std::cout << "fib(" << i << ") = " << fib(i) << '\n';
}

unsigned long long fib(size_t n)
{
	// Initialise fib(i) and fib(i+1) for the first iteration of the loop where i == 0
	unsigned long long fib_i{0};          // fib(i)   = fib(0) = 0
	unsigned long long fib_i_1{1};        // fib(i+1) = fib(1) = 1
	
	for (size_t i = 0; i < n; ++i)
	{
		auto fib_i_2 = fib_i + fib_i_1;   // fib(i+2) = fib(i) + fib(i+1)
		
		// Get ready for the next iteration (mind the order!):
		fib_i   = fib_i_1;
		fib_i_1 = fib_i_2;
	}
	
	// At the end of the loop, i was equal to n, so fib(i) == fib(n), which is what we needed
	return fib_i;
}