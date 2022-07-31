// Using using declarations and using directives
// (Note: example was not named in the text)
import <iostream>;
import squaring;

/* Make names from the math namespace available locally */
// Note: text uses hypot(), but this causes ambiguities with hypot() 
// function of <cmath> with Visual Studio
auto hypotenuse(const auto& x, const auto& y)
{
  using namespace math;
  // Or:
  //   using math::square;
  //   using math::sqrt;    /* Same as, of course: using std::sqrt; */
  return sqrt(square(x) + square(y));
}

int main()
{
  std::cout << "math::sqrt2 has the value " << math::sqrt2 << std::endl;
  std::cout << "This should be 0: " << (math::sqrt2 - std::numbers::sqrt2) << std::endl;
  std::cout << "This should be 2: " << math::square(math::sqrt2) << std::endl;
  std::cout << "This should be 5: " << hypotenuse(3, 4) << std::endl;
}
