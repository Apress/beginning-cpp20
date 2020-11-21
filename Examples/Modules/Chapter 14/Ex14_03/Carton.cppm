// Carton.cppm - defines the Carton class (with additional copy constuctor)
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

  // Copy constructor (wrong)
  Carton(const Carton& carton) : m_material {carton.m_material}
  { std::cout << "Carton copy constructor" << std::endl; }
/*
  // Copy constructor (correct)
  Carton(const Carton& carton) : Box{ carton }, m_material{ carton.m_material }
  { std::cout << "Carton copy constructor" << std::endl; }
*/
private:
  std::string m_material {"Cardboard"};
};

