export module boxes:tough_pack;
import :box;
import <iostream>;

export class ToughPack : public Box
{
public:
  ToughPack(double length, double width, double height)
    : Box{length, width, height}
  {
    std::println("ToughPack constructor called for a Box of volume {}", volume());
  }
  virtual ~ToughPack()
  {
    std::println("ToughPack destructor called for a Box of volume {}", volume());
  }

  // Function to calculate volume of a ToughPack allowing 13% for packing
  double volume() const override { return 0.87 * Box::volume(); }
};

