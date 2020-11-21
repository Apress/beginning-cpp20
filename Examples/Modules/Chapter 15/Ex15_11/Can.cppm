// Can.cppm Class defining a cylindrical can of a given height and diameter
export module can;

import vessel;
import <numbers>;

export class Can : public Vessel
{
public:
  Can(double diameter, double height) 
    : m_diameter {diameter}, m_height {height} {}    

  double volume() const override
  { 
    return std::numbers::pi * m_diameter * m_diameter * m_height / 4;
  }

private:
  double m_diameter, m_height;
};

