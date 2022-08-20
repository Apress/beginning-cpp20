export module boxes:carton;
import :box;
import <algorithm>;    // For std::max()
import <string>;
import <string_view>;

export class Carton : public Box
{
public:
  // Constructor explicitly calling the base constructor
  Carton(double l, double w, double h, std::string_view mat = "cardboard")
    : Box{l, w, h}, m_material{mat}
  {}

  // Function to calculate the volume of a Carton object
  double volume() const
  {
    return std::max(getLength() - 0.5, 0.0) 
         * std::max(getWidth() - 0.5, 0.0)
         * std::max(getHeight() - 0.5, 0.0);
  }

private:
  std::string m_material;
};
