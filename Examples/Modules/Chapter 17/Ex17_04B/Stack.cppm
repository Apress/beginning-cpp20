// Stack.cppm Templates to define stacks 
// (using std::unique_ptr<> instead of raw pointer)
export module stack;
import <stdexcept>;
import <memory>;       // For std::unique_ptr<>

/*
    The required changes are minimal, 
    but they do require std::move() which we only cover in Chapter 18.

    Other changes include:
      - no need for the destructor anymore (all memory is managed by smart pointers)
      - Nodes can no longer be copied, 
        so you need to construct all Nodes with the Node(const T&) constructor
 */

export template <typename T>
class Stack
{
public:
  Stack() = default;                  // Default constructor

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
    std::unique_ptr<Node> m_next{};   // Pointer to next node
  };

  std::unique_ptr<Node> m_head;     // Points to the top of the stack
};

// Copy constructor
template <typename T>
Stack<T>::Stack(const Stack& stack)
{
  if (stack.m_head)
  {
    m_head = std::make_unique<Node>(stack.m_head->m_item); // Copy the top node of the original
    Node* oldNode {stack.m_head.get()}; // Points to the top node of the original
    Node* newNode {m_head.get()};       // Points to the node in the new stack

    while (oldNode = oldNode->m_next.get()) // If m_next was nullptr, the last node was copied
    {     
      newNode->m_next = std::make_unique<Node>(oldNode->m_item); // Duplicate it
      newNode = newNode->m_next.get();      // Move to the node just created
    }
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
  // See Chapter 18 for std::move()
  auto node{ std::make_unique<Node>(item) }; // Create the new node
  node->m_next = std::move(m_head);   // Point to the old top node
  m_head = std::move(node);           // Make the new node the top
}

// Pop an object off the stack
template <typename T>
T Stack<T>::pop()
{
  if (isEmpty())     // If it's empty pop() is not valid so throw exception
    throw std::logic_error {"Stack empty"}; 

  // See Chapter 18 for std::move()
  auto next {std::move(m_head->m_next)}; // Save pointer to the next node
  T item {m_head->m_item};     // Save the T value to return later
  m_head.reset();              // Delete the current head
  m_head = std::move(next);    // Make head point to the next node
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
export template <typename T>
void swap(Stack<T>& one, Stack<T>& other) noexcept
{
  one.swap(other);     // Forward to public member function
}
