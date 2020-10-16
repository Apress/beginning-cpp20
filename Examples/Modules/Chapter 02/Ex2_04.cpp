// Using explicit type conversions
import <iostream>;

int main()
{
  const unsigned feet_per_yard{ 3 };
  const unsigned inches_per_foot{ 12 };
  const unsigned inches_per_yard{ feet_per_yard * inches_per_foot };

  double length{};        // Length as decimal yards
  unsigned int yards{};   // Whole yards
  unsigned int feet{};    // Whole feet
  unsigned int inches{};  // Whole inches

  std::cout << "Enter a length in yards as a decimal: ";
  std::cin >> length;

  // Get the length as yards, feet, and inches
  yards = static_cast<unsigned int>(length);
  feet = static_cast<unsigned int>((length - yards) * feet_per_yard);
  inches = static_cast<unsigned int>(length * inches_per_yard) % inches_per_foot;

  std::cout << length << " yards converts to "
    << yards << " yards "
    << feet << " feet "
    << inches << " inches." << std::endl;
}
