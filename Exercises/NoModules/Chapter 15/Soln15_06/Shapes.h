// Shape classes
#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include <numbers>

// Generic base class for shapes
class Shape
{
public:
  Shape(const Point& position) : m_position {position} {}
  virtual ~Shape() = default; // Remember: always use virtual destructors for base classes!

  virtual double area() const = 0;       // Pure virtual function to compute a shape's area
  virtual double perimeter() const = 0;  // Pure virtual function to compute a shape's perimeter
  virtual void scale(double factor) = 0; // Pure virtual function to scale a shape

  // Regular virtual function to move a shape
  virtual void move(const Point& position) { m_position = position; };  

private:
  Point m_position;          // Position of a shape
};

// Class defining a circle
class Circle : public Shape
{
public:
  Circle(const Point& center, double radius) : Shape{center}, m_radius{radius} {}

  double area() const override
  { 
    return m_radius * m_radius * std::numbers::pi;
  }
  double perimeter() const override
  {
    return 2 * std::numbers::pi * m_radius;
  }

  void scale(double factor) override { m_radius *= factor; }

private:
  double m_radius;   // Radius of a circle
};

// Class defining a rectangle
class Rectangle : public Shape
{

public:
  Rectangle(const Point& center, double rectWidth, double rectHeight) 
    : Shape{center}, m_width{rectWidth}, m_height{rectHeight} 
  {}

  double area() const override { return m_width * m_height; }
  double perimeter() const override { return 2 * (m_width + m_height); }
 
  void scale(double factor) override
  { 
    m_width *= factor; 
    m_height *= factor; 
  }

private:
  double m_width;        // Width of a rectangle
  double m_height;       // Height of a rectangle
};


#endif