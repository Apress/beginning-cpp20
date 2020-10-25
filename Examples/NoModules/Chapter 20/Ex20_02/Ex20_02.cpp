// Working with stacks and queues
#include <iostream>
#include <stack>
#include <queue>

int main()
{
  std::stack<int> stack;
  for (int i {}; i < 10; ++i)
    stack.push(i);

  std::cout << "The elements coming off the top of the stack:    ";
  while (!stack.empty())
  {
    std::cout << stack.top() << ' ';
    stack.pop();    // pop() is a void function!
  }
  std::cout << std::endl;

  std::queue<int> queue;
  for (int i {}; i < 10; ++i)
    queue.push(i);

  std::cout << "The elements coming from the front of the queue: ";
  while (!queue.empty())
  {
    std::cout << queue.front() << ' ';
    queue.pop();    // pop() is a void function!
  }
  std::cout << std::endl;
}