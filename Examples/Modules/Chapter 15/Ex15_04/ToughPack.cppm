export module boxes:tough_pack;

import :box;

export class ToughPack : public Box
{
public:
  // Inherit the Box(length, width, height) constructor
  using Box::Box;

  // Function to calculate volume of a ToughPack allowing 15% for packing
  double volume(int i = 500) const override
  {
    std::cout << "(ToughPack argument = " << i << ") ";
    return 0.85 * m_length * m_width * m_height;
  }
};

