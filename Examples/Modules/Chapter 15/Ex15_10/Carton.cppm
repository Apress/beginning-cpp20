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
  double volume() const override
  {
    const double volume {(m_length - 0.5) * (m_width - 0.5) * (m_height - 0.5)};
    return std::max(volume, 0.0);     // Or: return volume > 0.0 ? volume : 0.0; 
  }
private:
  std::string m_material;
};

