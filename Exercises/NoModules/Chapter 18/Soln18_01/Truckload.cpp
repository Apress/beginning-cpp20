#include "Truckload.h"

#include <iostream>
#include <stdexcept>    // For standard exception type std::out_of_range 
#include <string>       // For std::string and std::to_string()
#include <utility>      // For std::swap()

// Definition of the nested class member
// Since this member is private, 
// its definition can be moved to the source file.
class Truckload::Package
{
public:
  SharedBox m_box;      // Pointer to the Box object contained in this Package
  Package* m_next;      // Pointer to the next Package in the list

  Package(SharedBox box) : m_box{ box }, m_next{ nullptr } {} // Constructor
  ~Package() { delete m_next; }                           // Destructor
};

// Constructor - one Box (moved to source file to gain access to definition of Package)
Truckload::Truckload(SharedBox box)          
{
  m_head = m_tail = new Package{ box };
}

// Constructor - vector of Boxes
Truckload::Truckload(const std::vector<SharedBox>& boxes)
{
  for (const auto& box : boxes)
  {
    addBox(box);
  }
}

// Destructor: clean up the list (moved to source file to gain access to definition of Package)
Truckload::~Truckload()
{
  delete m_head;
}

// Copy constructor
Truckload::Truckload(const Truckload& src)
{
  for (Package* package{ src.m_head }; package; package = package->m_next)
  {
    addBox(package->m_box);
  }
}

// Copy assignment operator (updated to use copy-and-swap of course!)
Truckload& Truckload::operator=(const Truckload& src)
{
  auto copy{src};
  swap(copy);
  return *this;
}

// Move constructor (noexcept!)
Truckload::Truckload(Truckload&& src) noexcept
  : m_head{ src.m_head }
  , m_tail{ src.m_tail }
{
  // Do not forget to dislodge the linked list from the moved src Truckload
  src.m_head = src.m_tail = nullptr;
}

// Move assignment operator (noexcept + move-and-swap of course!)
Truckload& Truckload::operator=(Truckload&& src) noexcept
{
  auto moved{std::move(src)};
  swap(moved);
  return *this;
}

// Swap assignment operator (noexcept + move-and-swap of course!)
void Truckload::swap(Truckload& other) noexcept
{
  std::swap(m_head, other.m_head);
  std::swap(m_tail, other.m_tail);
}

// Optional yet conventional non-member function (forwards to member function)
void swap(Truckload& one, Truckload& other) noexcept
{
  one.swap(other);
}

Truckload::Iterator Truckload::getIterator() const { return Iterator{ m_head }; }

// Only thing we changed was adding "Iterator::" to the member's qualification
SharedBox Truckload::Iterator::getFirstBox()
{
  // Return m_head's box (or nullptr if the list is empty)
  m_current = m_head;
  return m_current? m_current->m_box : nullptr;
}

// Only thing we changed was adding "Iterator::" to the member's qualification
SharedBox Truckload::Iterator::getNextBox()
{
  if (!m_current)                                 // If there's no current...
    return getFirstBox();                         // ...return the 1st Box

  m_current = m_current->m_next;                  // Move to the next package

  return m_current? m_current->m_box : nullptr;   // Return its box (or nullptr...).
}

void Truckload::addBox(SharedBox box)
{
  auto package{ new Package{box} }; // Create a new Package

  if (m_tail)                      // Check list is not empty
    m_tail->m_next = package;      // Append the new object to the tail
  else                             // List is empty
    m_head = package;              // so new object is the head

  m_tail = package;                // Either way: the latest object is the (new) tail
}

bool Truckload::removeBox(SharedBox boxToRemove)
{
  Package* previous {nullptr};       // no previous yet
  Package* current {m_head};         // initialize current to the head of the list
  while (current)
  {
    if (current->m_box == boxToRemove)      // We found the Box!
    {
      // If there is a previous Package make it point to the next one (Figure 12.10)
      if (previous) previous->m_next = current->m_next;

      // Update pointers in member variables where required:
      if (current == m_head) m_head = current->m_next;
      if (current == m_tail) m_tail = previous;
                
      current->m_next = nullptr;     // Disconnect the current Package from the list
      delete current;                // and delete it
                                     
      return true;                   // Return true: we found and removed the box
    }                                
                                     // Move both pointers along (mind the order!)
    previous = current;              //  - first current becomes the new previous
    current = current->m_next;       //  - then move current along to the next Package
  }

  return false;     // Return false: boxToRemove was not found
}

SharedBox& Truckload::operator[](size_t index) const
{
  size_t count{};             // Package count
  for (Package* package{ m_head }; package; package = package->m_next)
  {
    if (count++ == index)      // Up to index yet?
      return package->m_box;   // If so return the pointer to Box
  }
  throw std::out_of_range{ "Index too large: " + std::to_string(index) };
}

std::ostream& operator<<(std::ostream& stream, const Truckload& load)
{
  size_t count{};
  auto iterator{ load.getIterator() };
  for (auto box{ iterator.getFirstBox() }; box; box = iterator.getNextBox())
  {
    std::cout << *box << ' ';
    if (!(++count % 4)) std::cout << std::endl;
  }
  if (count % 4) std::cout << std::endl;
  return stream;
}
