// Exercise 18-2 Exercising the LinkedList's move capabilities
// We do so by creating a linked list of std::unique_ptr<> elements: 
// a perfect example of an element type that cannot be copied!
import linked_list;
import <memory>;     // for std::unique_ptr<>
import <iostream>;
import <string_view>;

void printList(std::string_view message, const LinkedList<std::unique_ptr<int>>& list)
{
  std::cout << message << ": ";
  for (auto iterator{ list.front_iterator() }; iterator; iterator.next())
  {
    std::cout << *iterator.value() << ' ';
  }
  std::cout << std::endl;
}

int main()
{
  // In real life, you'd rarely use std::unique_ptr<int>. 
  // A more realistic use would be std::unique_ptr<ClassType>, 
  // where ClassType is a (potentially polymorphic) class type.
  // For our example here, std::unique_ptr<int> will do just fine:
  // the idea is simply to use an uncopyable type as template type argument for LinkedList.
  
  LinkedList<std::unique_ptr<int>> number_pointers;
  
  auto one{ std::make_unique<int>(1) };
  number_pointers.push_back(std::move(one));
  number_pointers.push_back(std::make_unique<int>(2));
  
  printList("Elements in the original list", number_pointers);
  
  LinkedList<std::unique_ptr<int>> move_constructed{std::move(number_pointers)};
  
  printList("Elements in the move constructed list", move_constructed);
  
  LinkedList<std::unique_ptr<int>> move_assigned;
  move_assigned = std::move(move_constructed);
  
  printList("Elements in the move assigned list", move_assigned);
}