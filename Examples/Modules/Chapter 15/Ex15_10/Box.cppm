export module boxes:box;

export class Box
{
public:
  Box(double l, double w, double h) : m_length {l}, m_width {w}, m_height {h} {}
  virtual ~Box() = default;            // Virtual destructor

  double getLength() const { return m_length; }
  double getWidth() const { return m_width; }
  double getHeight() const { return m_height; }

  virtual double volume() const = 0;   // Function to calculate the volume

private:
  double m_length, m_width, m_height;
};
