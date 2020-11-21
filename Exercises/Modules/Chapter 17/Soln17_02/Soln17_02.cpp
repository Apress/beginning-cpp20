// Exercise 16-2
// Create a basic Pair template
import pair;
import <iostream>;
import <string>;

int main()
{
  auto my_pair{ Pair<int, std::string>{122, "abc"} };
  ++my_pair.first;
  std::cout << "my_pair equals (" << my_pair.first 
            << ", " << my_pair.second << ')' << std::endl;

  auto pair1{ Pair<int, std::string>{0, "def"} };

  using namespace std::string_literals; // To make s suffix work (see below)
  
  // CTAD works as well. The deduced type for both pair2 and pair3 is Pair<int, std::string>:
  auto pair2{ Pair{123, std::string{"abc"}} }; // Option 1: specify std::string yourself (otherwise the type is const char[])
  auto pair3{ Pair{123, "def"s} };             // Option 2: use string literals: s suffix creates a std::string object

  std::cout << (pair1 < pair2 && pair2 < pair3? "operator< seems to be working" : "oops") << std::endl;
  std::cout << (pair1 == pair2? "oops" : "operator== works as well") << std::endl;
}