// Exercise 10-4.cpp
// Your very own interpretation of std::size()
import <iostream>;
import <array>;
import <vector>;
import <span>;

// Look ma, no sizeof()!
template <typename T, size_t N>
size_t my_size(const T (&array)[N]) { return N; }

// Overload with two other templates for std::vector<> and array<> 
template <typename T>
size_t my_size(const std::vector<T>& vector) { return vector.size(); }

template <typename T, size_t N>
size_t my_size(const std::array<T,N>& array) { return N; }  // or array.size();

/*
Instead of the latter two templates, you can create one template that would make my_size 
accept any argument and call size() on it. This will make it work
for std::array<> and std::vector<>, as well as std::string and many other containers:

template <typename Collection>
size_t my_size(const Collection& collection) { return collection.size(); }

Potential downside is that this will instantiate for int and double type arguments
as well, which may result in somewhat verbose compiler errors.
This issue can easily be fixed using a requires clause, though (see Chapter 21).

template <typename Collection> requires requires (const Collection c) { c.size(); }
size_t my_size(const Collection& collection) { return collection.size(); }
*/

int main()
{
  int array[] {4, 8, 15, 16, 23, 42};
  std::cout << "Size of numbers is " << my_size(array) << std::endl;
  
  // A string literal is also an array:
  std::cout << "Size of life lesson is " 
            << my_size("Always wear a smile. One size fits all.") << std::endl;
  
  std::vector<int> vector{4, 8, 15, 16, 23, 42};
  std::cout << "Size of vector is " << my_size(vector) << std::endl;
  
  std::array<int, 6> array_object{4, 8, 15, 16, 23, 42};
  std::cout << "Size of array_object is " << my_size(array_object) << std::endl;
}