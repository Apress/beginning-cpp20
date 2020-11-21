// A simple class for 2-dimensional points
export module point;

export class Point final
{
public:
  Point(double x, double y) : m_x{x}, m_y{y} {}
  
  double getX() const { return m_x; }
  double getY() const { return m_y; }
  
  void setX(double x) { m_x = x; }
  void setY(double y) { m_y = y; }
  
private:
  double m_x;
  double m_y;
};
