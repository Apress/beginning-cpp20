#ifndef PACKAGE_H
#define PACKAGE_H

#include "SharedBox.h"

class Package
{
public:
  Package(SharedBox box) : m_box{box}, m_next{nullptr} {}  // Constructor
  ~Package() { delete m_next; }                            // Destructor

  // Retrieve the Box pointer
  SharedBox getBox() const { return m_box; }

  // Retrieve or update the pointer to the next Package
  Package* getNext() { return m_next; }
  void setNext(Package* package) { m_next = package; }

private:
  SharedBox m_box;    // Pointer to the Box object contained in this Package
  Package* m_next;    // Pointer to the next Package in the list
};

#endif