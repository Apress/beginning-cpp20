// Create a << operator template for Pairs
import pair;
import <iostream>;
import <string>;

int main()
{
  // To make the s string literal suffix work 
  // (facilitates creation of Pairs using CTAD, or Constructor Template Argument Deduction).
  // This syntactic sugar for creating std::string objects is not really covered in the book.
  using namespace std::string_literals;

  auto my_pair{ Pair{122, "abc"s} };
  ++my_pair.first;
  std::cout << "my_pair equals " << my_pair << std::endl;

  auto pair1{ Pair{  0, "def"s} };
  auto pair2{ Pair{123, "abc"s} };
  auto pair3{ Pair{123, "def"s} };

  std::cout << (pair1 < pair2 && pair2 < pair3? "operator< seems to be working" : "oops") << std::endl;
  std::cout << (pair1 == pair2? "oops" : "operator== works as well") << std::endl;
}