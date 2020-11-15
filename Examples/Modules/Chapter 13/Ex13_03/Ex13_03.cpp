// Overloading <=> and == to fully support all comparison operators
import <iostream>;
import <format>;
import <string_view>;
import <vector>;
import box;

void show(const Box& box)
{
  std::cout << std::format("Box({:.1f}, {:.1f}, {:.1f})", 
                  box.getLength(), box.getWidth(), box.getHeight());
}
void show(const Box& box1, std::string_view relationship, const Box& box2)
{
  show(box1); std::cout << relationship; show(box2); std::cout << std::endl;
}

int main()
{
  const std::vector boxes {Box {2.0, 1.5, 3.0}, Box {1.0, 3.0, 5.0},
                           Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 2.0}};
  const Box theBox {3.0, 1.0, 4.0};

  for (const auto& box : boxes)
    if (theBox > box) show(theBox, " is greater than ", box);  // > works

  std::cout << std::endl;

  for (const auto& box : boxes)
    if (theBox != box) show(theBox, " is not equal to ", box); // != works

  std::cout << std::endl;  

  for (const auto& box : boxes)
    if (6.0 <= box)                     // Yes, even double <= Box works!!
      { std::cout << "6 is less than or equal to "; show(box); std::cout << std::endl; }
}
