// Writing through a view
import <iostream>;
import <vector>;
import <ranges>;   // For views, range factories, and range adaptors

bool isEven(int i) { return i % 2 == 0; }

int main()
{
  std::vector numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  for (int& i : numbers | std::ranges::views::filter(isEven))
    i *= i;

  for (int i : numbers) std::cout << i << ' ';
  std::cout << std::endl;
}
