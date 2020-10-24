// Stack.h Templates to define stacks
#ifndef STACK_H
#define STACK_H
#include <stdexcept>

template <typename T>
class Stack
{
public:
  Stack() = default;                  // Default constructor
  ~Stack();                           // Destructor

  Stack(const Stack & stack);          // Copy constructor
  Stack& operator=(const Stack & rhs); // Copy assignment operator
  void swap(Stack & other) noexcept;   // noexcept swap() function

  void push(const T & item);           // Push an object onto the stack
  T pop();                            // Pop an object off the stack
  bool isEmpty() const;               // Empty test

private:
  // Nested class
  class Node
  {
  public:
    Node(const T& item) : m_item{ item } {} // Create a node from an object

    T m_item;          // The object stored in this node
    Node* m_next{};   // Pointer to next node
  };

  Node* m_head{};     // Points to the top of the stack
};

// Copy constructor
template <typename T>
Stack<T>::Stack(const Stack& stack)
{
  if (stack.m_head)
  {
    m_head = new Node {*stack.m_head}; // Copy the top node of the original
    Node* oldNode {stack.m_head};      // Points to the top node of the original
    Node* newNode {m_head};            // Points to the node in the new stack

    while (oldNode = oldNode->m_next)  // If m_next was nullptr, the last node was copied
    {     
      newNode->m_next = new Node{*oldNode}; // Duplicate it
      newNode = newNode->m_next;            // Move to the node just created
    }
  }
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
  while (m_head)
  {                               // While current pointer is not null
    auto* next{ m_head->m_next }; // Get the pointer to the next node
    delete m_head;                // Delete the current head
    m_head = next;                // Make m_head point to the next node
  }
}

// Copy assignment operator
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& rhs)
{
  auto copy{ rhs }; // Copy...        (could go wrong and throw an exception)
  swap(copy);       // ... and swap!  (noexcept)
  return *this;
}

// Push an object onto the stack
template <typename T>
void Stack<T>::push(const T& item)
{
  Node* node{ new Node{item} }; // Create the new node
  node->m_next = m_head;  // Point to the old top node
  m_head = node;          // Make the new node the top
}

// Pop an object off the stack
template <typename T>
T Stack<T>::pop()
{
  if (isEmpty())     // If it's empty pop() is not valid so throw exception
    throw std::logic_error {"Stack empty"}; 

  auto* next {m_head->m_next}; // Save pointer to the next node
  T item {m_head->m_item};     // Save the T value to return later
  delete m_head;               // Delete the current head
  m_head = next;               // Make head point to the next node
  return item;                 // Return the top object
}

template <typename T>
bool Stack<T>::isEmpty() const { return m_head == nullptr; }

// noexcept swap member function
template <typename T>
void Stack<T>::swap(Stack& other) noexcept
{
  std::swap(m_head, other.m_head);
}

// Conventional noexcept swap non-member function
template <typename T>
void swap(Stack<T>& one, Stack<T>& other) noexcept
{
  one.swap(other);     // Forward to public member function
}

#endif
