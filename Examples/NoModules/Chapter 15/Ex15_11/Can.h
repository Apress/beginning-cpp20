// Can.h Class defining a cylindrical can of a given height and diameter
#ifndef CAN_H
#define CAN_H

#include "Vessel.h"
#include <numbers>

class Can : public Vessel
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

#endif
