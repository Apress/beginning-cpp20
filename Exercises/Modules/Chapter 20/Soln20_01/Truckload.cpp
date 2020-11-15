module truckload;

import <iostream>;
import <algorithm>;

// Constructor - one Box
Truckload::Truckload(SharedBox box)
  : m_boxes{ 1, box }
{
}

// Constructor - vector of Boxes
Truckload::Truckload(std::vector<SharedBox> boxes)
  : m_boxes{ std::move(boxes) }
{
}

// Swap assignment operator (noexcept)
void Truckload::swap(Truckload& other) noexcept
{
  m_boxes.swap(other.m_boxes);
}

// Optional yet conventional non-member function (forwards to member function)
void swap(Truckload& one, Truckload& other) noexcept
{
  one.swap(other);
}

Truckload::Iterator Truckload::getIterator() const { return Iterator{ m_boxes }; }

// Only thing we changed was adding "Iterator::" to the member's qualification
SharedBox Truckload::Iterator::getFirstBox()
{
  // Return m_head's box (or nullptr if the list is empty)
  m_current = m_boxes->begin();
  return m_current != m_boxes->end() ? *m_current : SharedBox{};
}

// Only thing we changed was adding "Iterator::" to the member's qualification
SharedBox Truckload::Iterator::getNextBox()
{
  if (m_current == m_boxes->end())                // If there's no current...
    return getFirstBox();                         // ...return the 1st Box

  ++m_current;                                    // Move to the next package

  return m_current != m_boxes->end() ? *m_current : SharedBox{};
}

void Truckload::addBox(SharedBox box)
{
  m_boxes.push_back(std::move(box));
}

bool Truckload::removeBox(SharedBox boxToRemove)
{
  // Unlike the original implementation, 
  // std::erase() removes all occurrences of boxToRemove.
  // If that is not acceptable, you can use find() as shown below...
  return std::erase(m_boxes, boxToRemove) > 0;

// Remove only the first occurrence of boxToRemove
/*
  if (auto found{ std::ranges::find(m_boxes, boxToRemove) }; found != end(m_boxes))
  {
    m_boxes.erase(found);
    return true;
  }
  else
  {
    return false;
  }
*/
}

SharedBox& Truckload::operator[](size_t index)
{
  // Original implementation performed bounds checking, so use at() instead of []
  return m_boxes.at(index);
}

SharedBox Truckload::operator[](size_t index) const
{
  // Original implementation performed bounds checking, so use at() instead of []
  return m_boxes.at(index);
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
