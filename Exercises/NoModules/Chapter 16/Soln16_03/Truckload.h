#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include "Box.h"

#include <memory>
#include <vector>
#include <ostream>

using SharedBox = std::shared_ptr<Box>;

class Truckload
{
public:
  Truckload() = default;            // Default constructor - empty truckload

  Truckload(SharedBox box);         // Constructor - one Box
  Truckload(const std::vector<SharedBox>& boxes);  // Constructor - vector of Boxes
  
  Truckload(const Truckload& src);  // Copy constructor
  Truckload& operator=(const Truckload& other);  // Copy assignment operator

  ~Truckload();                     // Destructor

  class Iterator;      // Declaration of a public nested class, Truckload::Iterator

  Iterator getIterator() const;

  void addBox(SharedBox box);       // Add a new SharedBox
  bool removeBox(SharedBox box);    // Remove a Box from the Truckload

  SharedBox& operator[](size_t index) const;   // Overloaded subscript operator

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
  SharedBox getFirstBox();  // Get the first Box
  SharedBox getNextBox();   // Get the next Box

private:
  Package* m_head;          // The head of the linked list (needed for getFirstBox())
  Package* m_current;       // The package whose Box was last retrieved

  friend class Truckload;   // Only a Truckload can create an Iterator
  explicit Iterator(Package* head) : m_head{ head }, m_current{ nullptr } {}
};

std::ostream& operator<<(std::ostream& stream, const Truckload& load);

#endif