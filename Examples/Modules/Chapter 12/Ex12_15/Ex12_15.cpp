// Defining and using static constants
import <iostream>;
import cylindrical;

int main()
{
  CylindricalBox bigBox{ 1.23f,
            CylindricalBox::s_max_height, CylindricalBox::s_default_material };
  std::cout << "The volume of bigBox is " <<  bigBox.volume() << std::endl;
}
