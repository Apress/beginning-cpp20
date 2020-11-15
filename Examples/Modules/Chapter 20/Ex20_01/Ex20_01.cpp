// Working with std::deque<>
#include <iostream>
#include <deque>

int main()
{
  std::deque<int> my_deque;  // A deque<> allows efficient insertions 
  my_deque.push_back(2);     // to both ends of the sequence
  my_deque.push_back(4);
  my_deque.push_front(1);

  my_deque[2] = 3;           // A deque<> is a random-access sequence container

  std::cout << "There are " << my_deque.size() << " elements in my_deque: ";

  for (int element : my_deque) // A deque<>, like all containers, is a range
    std::cout << element << ' ';
  std::cout << std::endl;
}
