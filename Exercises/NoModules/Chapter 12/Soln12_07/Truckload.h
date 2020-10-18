#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include "Box.h"

#include <memory>
#include <vector>

using SharedBox = std::shared_ptr<Box>;

class Truckload
{
public:
  Truckload() = default;            // Default constructor - empty truckload

  Truckload(SharedBox box);         // Constructor - one Box
  Truckload(const std::vector<SharedBox>& boxes);  // Constructor - vector of Boxes
  Truckload(const Truckload& src);  // Copy constructor

  ~Truckload();                     // Destructor

  class Iterator;      // Declaration of a public nested class, Truckload::Iterator

  Iterator getIterator() const;

  void addBox(SharedBox box);       // Add a new SharedBox
  bool removeBox(SharedBox box);    // Remove a Box from the Truckload

  void listBoxes() const;           // Output the Boxes
  void listBoxesReversed() const;   // Output the Boxes in reversed order

private:
  class Package;

  Package* m_head {};               // First in the list
  Package* m_tail {};               // Last in the list
};

// Out-of-class definition of the nested Iterator class 
// (class itself is part of the public interface, so belongs in the header)
class Truckload::Iterator
{
public:
  SharedBox getFirstBox();    // Get the first Box
  SharedBox getLastBox();     // Get the first Box
  SharedBox getNextBox();     // Get the next Box
  SharedBox getPreviousBox(); // Get the previous Box

private:
  Package* m_head;          // The head of the linked list (needed for getFirstBox())
  Package* m_tail;          // The tail of the linked list (needed for getLastBox())
  Package* m_current;       // The package whose Box was last retrieved

  friend class Truckload;   // Only a Truckload can create an Iterator
  explicit Iterator(Package* head, Package* tail) 
    : m_head{ head }
    , m_tail{ tail }
    , m_current{ nullptr } 
  {}
};

#endif