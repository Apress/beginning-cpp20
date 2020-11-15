export module boxes:carton;
import <algorithm>;    // For std::max()
import <string>;
import <string_view>;
import :box;

export class Carton : public Box
{
public:
  // Constructor explicitly calling the base constructor
  Carton(double l, double w, double h, std::string_view mat = "cardboard")
    : Box{l, w, h}, m_material{mat}
  {}

  // Function to calculate the volume of a Carton object
  double volume(int i = 50) const override
  {
    std::cout << "(Carton argument = " << i << ") ";
    return std::max((m_length - 0.5) * (m_width - 0.5) * (m_height - 0.5), 0.0);
  }

private:
  std::string m_material;
};

