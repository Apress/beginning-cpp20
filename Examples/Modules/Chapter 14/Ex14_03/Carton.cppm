// Carton.cppm - defines the Carton class (with additional copy constuctor)
export module carton;

import <string>;
import <string_view>;
#include <print>
import box;

export class Carton : public Box
{
public:
  Carton() { std::println("Carton() called."); }

  explicit Carton(std::string_view material) : m_material{material}
  { std::println("Carton(string_view) called."); }

  Carton(double side, std::string_view material) : Box{side}, m_material{material}
  { std::println("Carton(double,string_view) called."); }

  Carton(double l, double w, double h, std::string_view material)
    : Box{l, w, h}, m_material{material}
    { std::println("Carton(double, double, double, string_view) called.)"); }  

  // Copy constructor (wrong)
  Carton(const Carton& carton) : m_material {carton.m_material}
  { std::println("Carton copy constructor"); }
/*
  // Copy constructor (correct)
  Carton(const Carton& carton) : Box{ carton }, m_material{ carton.m_material }
  { std::println("Carton copy constructor"); }
*/
private:
  std::string m_material {"Cardboard"};
};

