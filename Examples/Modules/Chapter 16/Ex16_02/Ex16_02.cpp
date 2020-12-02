// Throw an exception object
import <iostream>;
import <string_view>;    // for operator<<
import troubles;

void trySomething(int i);

int main()
{
  for (int i {}; i < 2; ++i)
  {
    try
    {
      trySomething(i);
    }
    catch (const Trouble& t)
    {
      // What seems to be the trouble?
      std::cout << "Exception: " << t.what() << std::endl;
    }
  }
}

void trySomething(int i)
{
  // There's always trouble when ‘trying something’...
  if (i == 0)
    throw Trouble {};
  else
    throw Trouble {"Nobody knows the trouble I've seen..."};
}
