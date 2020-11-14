module truckload;
import <iostream>;

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

// Copy constructor
Truckload::Truckload(const Truckload& src)
{
  for (Package* package{ src.m_head }; package; package = package->m_next)
  {
    addBox(package->m_box);
  }
}

// Destructor: clean up the list (moved to source file to gain access to definition of Package)
Truckload::~Truckload()
{
  delete m_head;
}

void Truckload::listBoxes() const
{
  const size_t boxesPerLine{ 4 };
  size_t count {};  
  for (Package* package{m_head}; package; package = package->m_next)
  {
    std::cout << ' ';
    package->m_box->listBox();
    if (! (++count % boxesPerLine)) std::cout << std::endl;
  }
  if (count % boxesPerLine) std::cout << std::endl;
}


SharedBox Truckload::getFirstBox()
{
  // Return m_head's box (or nullptr if the list is empty)
  m_current = m_head;
  return m_current? m_current->m_box : nullptr;
}

SharedBox Truckload::getNextBox()
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
      if (current == m_current) m_current = current->m_next;
                                     
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
