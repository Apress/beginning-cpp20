export module cylindrical;

import <string>;
import <string_view>;

export class CylindricalBox
{
public:
  static inline const float s_max_radius { 35.0f };
  static inline const float s_max_height { 60.0f };
  static inline const std::string_view s_default_material { "paperboard" };

  CylindricalBox(float radius, float height,
                 std::string_view material = s_default_material);
  float volume() const;

private:
  // The value of PI used by CylindricalBox's volume() function
  static inline const float PI { 3.141592f };  

  float m_radius;
  float m_height;
  std::string m_material;
};
