// Finding boxes.
import <iostream>;
import <vector>;
import <algorithm>;
import box;      // From Ex13_03A

int main()
{
  std::vector boxes{ Box{1,2,3}, Box{5,2,3}, Box{9,2,1}, Box{3,2,1} };

  // Define a lambda functor to print the result of find() or find_if():
  auto print_result{ [&boxes] (auto result)
  {
    if (result == end(boxes))
      std::cout << "No box found." << std::endl;
    else
      std::cout << "Found matching box at position "
                << (result - begin(boxes)) << std::endl;
  }};

  // Find an exact box
  Box box_to_find{ 3,2,1 };
  auto result{ std::find(begin(boxes), end(boxes), box_to_find) };
  print_result(result);

  // Find a box with a volume larger than that of box_to_find
  const auto required_volume{ box_to_find.volume() };
  result = std::find_if(begin(boxes), end(boxes),
              [required_volume](const Box& box) { return box > required_volume; });
  print_result(result);
}
