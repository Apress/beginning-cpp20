// Class template instantiation errors
import <set>;
import <list>;
import <vector>;
import <algorithm>;

class MyClass { /* just a dummy class */ };

int main()
{
  std::vector<int&> v;

  MyClass one, other;
  auto biggest{ std::max(one, other) };

  std::set<MyClass> objects;
  objects.insert(MyClass{});

  std::list numbers{ 4, 1, 3, 2 };
  std::sort(begin(numbers), end(numbers));
}
