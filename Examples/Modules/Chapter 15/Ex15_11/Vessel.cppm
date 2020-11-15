// Vessel.cppm  Abstract class defining a vessel
export module vessel;

export class Vessel
{
public:
  virtual ~Vessel() = default;         // As always: a virtual destructor!
  virtual double volume() const = 0;
};

