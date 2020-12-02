// Catching exceptions with a base class handler
import <iostream>;
import <typeinfo>;			// for the type_info type returned by the typeid operator
import <string_view>;       // for operator<<
import troubles;

int main()
{
  for (int i {}; i < 7; ++i)
  {
    try
    {
      if (i == 3)
        throw Trouble{};
      else if (i == 5)
        throw MoreTrouble{};
      else if (i == 6)
        throw BigTrouble{};
    }
    catch (const Trouble& t)
    {
      //std::cout << "Trouble object caught: " << t.what() << std::endl;
      std::cout << typeid(t).name() << " object caught: " << t.what() << std::endl;
    }
    std::cout << "End of the for loop (after the catch blocks) - i is " << i << std::endl;
  }
}
