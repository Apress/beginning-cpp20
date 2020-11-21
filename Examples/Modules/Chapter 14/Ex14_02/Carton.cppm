// Carton.cppm - defines the Carton class with the Box class as base
export module carton;

import <string>;
import <string_view>;
import <iostream>;
import box;

export class Carton : public Box
{
public:
  Carton() { std::cout << "Carton() called.\n"; }

  explicit Carton(std::string_view material) : m_material{material}
  { std::cout << "Carton(string_view) called.\n"; }

  Carton(double side, std::string_view material) : Box{side}, m_material{material}
  { std::cout << "Carton(double,string_view) called.\n"; }

  Carton(double l, double w, double h, std::string_view material)
    : Box{l, w, h}, m_material{material}
    { std::cout << "Carton(double,double,double,string_view) called.\n"; }  
/*
  // This constructor won't compile!
  Carton::Carton(double l, double w, double h, std::string_view material)
    : m_length{ l }, m_width{ w }, m_height{ h }, m_material{ material }
    { std::cout << "Carton(double,double,double,string_view) called.\n"; }
*/
/*
  // Constructor that will compile!
  Carton::Carton(double l, double w, double h, std::string_view material)
    : m_material{material}
  {
    m_length = l;  // These should normally be initialized in a base class constructor...
    m_width = w;
    m_height = h;
    std::cout << "Carton(double,double,double,string_view) called.\n";
  }
*/

private:
  std::string m_material {"Cardboard"};
};

