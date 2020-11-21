// A custom RAII class to manage a dynamic double[] array resource
export module raii;
import <iostream>;

export class DoubleArrayRAII final
{
public:
  explicit DoubleArrayRAII(size_t size) : m_resource{ new double[size] } {}
  ~DoubleArrayRAII()
  {
    std::cout << "Freeing memory..." << std::endl;
    delete[] m_resource;
  }

  // Delete copy constructor and assignment operator
  DoubleArrayRAII(const DoubleArrayRAII&) = delete;
  DoubleArrayRAII& operator=(const DoubleArrayRAII&) = delete;

  // Array subscript operator
  double& operator[](size_t index) noexcept { return m_resource[index]; }
  const double& operator[](size_t index) const noexcept { return m_resource[index]; }

  // Function to access the encapsulated resource
  double* get() const noexcept { return m_resource; }

  // Function to instruct the RAII object to hand over the resource.
  // Once called, the RAII object shall no longer release the resource
  // upon destruction anymore. Returns the resource in the process.
  double* release() noexcept
  {
    double* result = m_resource;
    m_resource = nullptr;
    return result;
  }

private:
  double* m_resource;
};
