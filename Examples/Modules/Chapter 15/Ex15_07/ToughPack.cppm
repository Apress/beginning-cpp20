export module boxes:tough_pack;

import :box;
import <iostream>;

export class ToughPack : public Box
{
public:
  // Inherit the Box(length, width, height) constructor
  using Box::Box;
  ~ToughPack() { std::cout << "ToughPack destructor called" << std::endl; }

protected:
  // Function to calculate volume of a ToughPack allowing 15% for packing
  double volume() const override { return 0.85 * m_length * m_width * m_height; }
};

