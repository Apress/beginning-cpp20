// Creating and working with Standard iterators
import <vector>;
import <iostream>;

int main()
{
  std::vector<char> letters{ 'a', 'b', 'c', 'd', 'e' };
  auto my_iter{ letters.begin() };

  std::cout << *my_iter << std::endl;       // a

  *my_iter = 'x';
  std::cout << letters[0] << std::endl;     // x

  ++my_iter;                                // Move my_iter to the next element
  std::cout << *my_iter << std::endl;       // b

  my_iter += 2;                             // Move my_iter two elements further
  std::cout << *my_iter-- << std::endl;     // d
  std::cout << *my_iter << std::endl;       // c (iterator altered using the post-decrement
                                            //    operator in the previous statement)
  auto copy{ my_iter };                     // Create a copy of my_iter (pointing at c)
  my_iter += 2;                             // Move my_iter two elements further
  std::cout << *copy << std::endl;          // c (copy not affected by moving my_iter)
  std::cout << *my_iter << std::endl;       // e
  std::cout << my_iter - copy << std::endl; // 2
}
