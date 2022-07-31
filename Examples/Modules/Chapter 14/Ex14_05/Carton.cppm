// Carton.cppm - defines the Carton class with the Box class as base
export module carton;

import <string>;
import <string_view>;
import <iostream>;
import box;

export class Carton : public Box
{
  using Box::Box;  // Inherit Box class constructors 

public:
  Carton() = default;   // Required by Visual C++
  Carton(double length, double width, double height, std::string_view mat)
     : Box{length, width, height}, m_material{mat}
     { std::cout << "Carton(double,double,double,string_view) called.\n"; }

private:
  std::string m_material {"Cardboard"};
};

