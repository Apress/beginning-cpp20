#include <iostream>
#include "CylindricalBox.h"

CylindricalBox::CylindricalBox(float radius, float height, std::string_view material)
  : m_radius{ radius }
  , m_height{ height }
  , m_material{ material }
{
  std::cout << "Box constructed consisting of " << material;
  if (material == s_default_material)
  {
    std::cout << " (the default material!)";
  }
  std::cout << std::endl;
}

float CylindricalBox::volume() const
{
  return PI * m_radius * m_radius * m_height;
}

