// Using range adaptors
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>   // For std::back_inserter()
#include <ranges>
#include "Box.h"

using namespace std::ranges::views;

int main()
{
  // Our challenge: given a sequence of boxes, 
  // gather pointers to all boxes larger than required_volume
  std::vector<Box> boxes{ { 1, 2, 3 }, { 4, 5, 6}, { 7, 8, 9 }, { 10, 11, 12 } };
  const double required_volume{ 200 };

  // Without range-based algorithms and range adaptors (in two steps):
  std::vector<Box*> box_pointers;
  std::transform(begin(boxes), end(boxes), back_inserter(box_pointers),
    [](Box& box) { return &box; });
  std::vector<Box*> large_boxes;
  std::copy_if(begin(box_pointers), end(box_pointers), back_inserter(large_boxes),
    [=](const Box* box) { return *box >= required_volume; });

  std::cout << "There are " << large_boxes.size() << " large boxes." << std::endl;

  // With range-based algorithm copy() and a filter-transform pipeline
  std::vector<Box*> large_boxes_ranges_copy;
  std::ranges::copy(
    boxes | filter([=](const Box& box) { return box >= required_volume; })
          | transform([](Box& box) { return &box; }),
    back_inserter(large_boxes_ranges_copy)
  );

  // With range-based algorithm copy_if() and transform adaptor
  std::vector<Box*> large_boxes_ranges_copy_if;
  std::ranges::copy_if(    /* Transform using adaptor before filtering in copy_if() */
     boxes | transform([](Box& box) { return &box; }),       // Input view of boxes
     back_inserter(large_boxes_ranges_copy_if),              // Output iterator
     [=](const Box* box) { return *box >= required_volume; } // Condition for copy_if()
  );

  // With range-based algorithm transform() and a filter adaptor
  std::vector<Box*> large_boxes_ranges_transform;
  std::ranges::transform(  /* Filter using adaptor before transforming using algorithm */
     boxes | filter([=](const Box& box) { return box >= required_volume; }),
     back_inserter(large_boxes_ranges_transform),          // Output iterator
     [](Box& box) { return &box; }        // Transform functor of transform()
  );

  if (large_boxes_ranges_copy != large_boxes
    || large_boxes_ranges_copy_if != large_boxes
    || large_boxes_ranges_transform != large_boxes)
  {
    std::cerr << "Oh dear... One of the range-based algorithms gave a different result!" << std::endl;
  }
}
