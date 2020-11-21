export module linked_list;

/*
This LinkedList template follows some (not all) conventions of Standard Library containers:
some member function names are analogous,
as is the choice not to work with exceptions in case you do something wrong
(such as calling back() or pop_front() on an empty list).
The latter has the implication that if you mis-use the container,
your program will likely crash...
*/

import <utility>;        // for std::swap()

export template<typename T>
class LinkedList
{
public:
	LinkedList() = default;                      // Default constructor (all pointers are initialised to nullptr)
	~LinkedList();

	LinkedList(const LinkedList& list);          // Copy constructor
	LinkedList& operator=(LinkedList list);      // Assignment operator

	void push_front(const T& value);             // Add an object to the head
	void push_back(const T& value);              // Add an object to the tail

	void pop_back();                             // Removes the last element from the list (undefined behavior for empty lists)
	void pop_front();                            // Removes the first element from the list (undefined behavior for empty lists)

	T& front();                                  // Get the object at the head (undefined behavior for empty lists)
	T& back();                                   // Get the object at the tail (undefined behavior for empty lists)
	const T& front() const;                      // Get the object at the head (undefined behavior for empty lists)
	const T& back() const;                       // Get the object at the tail (undefined behavior for empty lists)

	bool empty() const;                          // Checks whether the list is empty or not
	void clear();                                // Function to remove all elements from the list
	size_t size() const;                         // Get the number of elements from the list

	class Iterator;                              // Nested Iterator class declaration (definition below)
	Iterator front_iterator() const;             // Get an Iterator that starts at the head
	Iterator back_iterator() const;              // Get an Iterator that starts at the tail

	void swap(LinkedList& other) noexcept;       // Swap function

private:
	class Node                                   // Node class definition
	{
	public:
		Node(const T& theValue)
			: m_value{ theValue }, m_next{}, m_previous{}
		{}

		T m_value;
		Node* m_next;
		Node* m_previous;
	};

	Node* m_head{};    // Pointer to first node
	Node* m_tail{};    // Pointer to last node
	size_t m_size{};
};

// Non-member swap function.
// Convention dictates swap is present as non-member function.
// For class types it is often easiest (and recommended) 
// to implement it using a member swap function.
export template<typename T>
void swap(LinkedList<T>& one, LinkedList<T>& other)
{
	one.swap(other);
}

// ---------------------------------------------
// Member definitions
// ---------------------------------------------

// Destructor template
template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

// Copy constructor template
template<typename T>
LinkedList<T>::LinkedList(const LinkedList& list)
{
  // Use existing members (iteration, push_back()) to implement the copying
  // This avoids duplicating any code that manipulates the list's pointers / size members.
  for (auto iterator{ list.front_iterator() }; iterator; iterator.next())
    push_back(iterator.value());
}

// Assignment operator template (uses copy-and-swap idiom)
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList copy)
{
	swap(*this, copy);
	return *this;
}

// Template for member functions that add an object to the head of the list
template<typename T> 
void LinkedList<T>::push_front(const T& value)
{
	// Note: this function is strongly exception-safe because
	// any and all change occur after the line annotated with (*),
	// which is the only line that may throw.

	Node* oldHead{ m_head };
	m_head = new Node{ value };  // (*)
	++m_size;

	if (oldHead)
	{
		oldHead->m_previous = m_head;
		m_head->m_next = oldHead;
	}
	else  // list was empty before, and now has one element
	{
		m_tail = m_head;
	}
}

// Template for member functions that add an object to the tail of the list
template<typename T>
void LinkedList<T>::push_back(const T& value)
{
	// Note: this function is strongly exception-safe because
	// any and all change occur after the line annotated with (*),
	// which is the only line that may throw.

	Node* oldTail{ m_tail };
	m_tail = new Node{value};	 // (*)
	++m_size;                 

	if (oldTail)
	{
		oldTail->m_next = m_tail;
		m_tail->m_previous = oldTail;
	}
	else  // list was empty before, and now has one element
	{
		m_head = m_tail;
	}
}

// Template for member functions that remove an object from the head of the list
template<typename T> 
void LinkedList<T>::pop_front()
{
	Node* oldHead{ m_head };
	if (oldHead == m_tail)
	{
		m_head = m_tail = nullptr;
	}
	else
	{
		m_head = oldHead->m_next;
		m_head->m_previous = nullptr;
	}
	
	--m_size;
	delete oldHead;
}

// Template function member to remove an object from the tail of the list
template<typename T>
void LinkedList<T>::pop_back()
{
	Node* oldTail{ m_tail };
	if (oldTail == m_head)
	{
		m_head = m_tail = nullptr;
	}
	else
	{
		m_tail = oldTail->m_previous;
		m_tail->next = nullptr;
	}

	--m_size;
	delete oldTail;
}

// Template function members to get the object at the head of the list
template<typename T>
T& LinkedList<T>::front()
{
	return m_head->value;
}
template<typename T>
const T& LinkedList<T>::front() const
{
	return m_head->value;
}

// Template function members to get the object at the tail of the list
template<typename T>
T& LinkedList<T>::back()
{
	return m_tail->value;
}
template<typename T>
const T& LinkedList<T>::back() const
{
	return m_tail->value;
}

// Check whether list is empty or not
template<typename T>
bool LinkedList<T>::empty() const
{
	return m_size == 0;  // (or m_head == nullptr, or m_tail == nullptr)
}

// Template to get the size of a list
template<typename T> 
size_t LinkedList<T>::size() const
{
	return m_size;
}

// Template to clear a list
template<typename T>
void LinkedList<T>::clear()
{
	// Use existing functions (avoid code duplication!)
	while (!empty()) pop_front();
}

// Member function template to swap two lists
template<typename T>
void LinkedList<T>::swap(LinkedList& other) noexcept
{
	std::swap(m_head, other.m_head);
	std::swap(m_tail, other.m_tail);
	std::swap(m_size, other.m_size);
}

// Definition of the nested Iterator class
template<typename T>
class LinkedList<T>::Iterator
{
public:
	explicit Iterator(Node* node) 
		: m_current{ node }
	{}

	const T& value() const { return m_current->m_value; }

	bool hasValue() const { return m_current != nullptr; }
	operator bool() const { return m_current != nullptr; }

	void next() { m_current = m_current->m_next; }
	void previous() { m_current = m_current->m_previous; }

private:
	Node* m_current;
};

// Get an Iterator that starts at the head
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::front_iterator() const
{
  return Iterator{ m_head };
}

// Get an Iterator that starts at the tail
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::back_iterator() const
{
  return Iterator{ m_tail };
}
