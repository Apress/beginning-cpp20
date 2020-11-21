// Carton.cppm - defines the Carton class with the Box class as private base
export module carton;

import <string>;
import <string_view>;
import box;

export class Carton : private Box
{
public:
  explicit Carton(std::string_view mat = "Cardboard") : m_material {mat} {}
  using Box::volume; // Inherit as public

private:
  std::string m_material;
};

