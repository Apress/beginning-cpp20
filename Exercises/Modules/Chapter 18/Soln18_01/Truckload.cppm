export module truckload;

import box;

import <memory>;
import <vector>;
import <ostream>;

export using SharedBox = std::shared_ptr<Box>;

export class Truckload
{
public:
  Truckload() = default;            // Default constructor - empty truckload
  ~Truckload();                     // Destructor

  Truckload(SharedBox box);         // Constructor - one Box
  Truckload(const std::vector<SharedBox>& boxes);  // Constructor - vector of Boxes

  Truckload(const Truckload& src);  // Copy constructor
  Truckload& operator=(const Truckload& src);  // Copy assignment operator

  Truckload(Truckload&& src) noexcept;  // Move constructor
  Truckload& operator=(Truckload&& src) noexcept;  // Move assignment operator

  void swap(Truckload& other) noexcept;

  class Iterator;      // Declaration of a public nested class, Truckload::Iterator

  Iterator getIterator() const;

  void addBox(SharedBox box);       // Add a new SharedBox
  bool removeBox(SharedBox box);    // Remove a Box from the Truckload

  SharedBox& operator[](size_t index) const;   // Overloaded subscript operator

private:
  class Package;

  Package* m_head {};               // First in the list
  Package* m_tail {};               // Last in the list
};

// Out-of-class definition of the nested Iterator class 
// (class itself is part of the public interface, so belongs in a module interface file)
class Truckload::Iterator
{
public:
  SharedBox getFirstBox();  // Get the first Box
  SharedBox getNextBox();   // Get the next Box

private:
  Package* m_head;          // The head of the linked list (needed for getFirstBox())
  Package* m_current;       // The package whose Box was last retrieved

  friend class Truckload;   // Only a Truckload can create an Iterator
  explicit Iterator(Package* head) : m_head{ head }, m_current{ nullptr } {}
};

export std::ostream& operator<<(std::ostream& stream, const Truckload& load);

// Optional yet conventional non-member function (forwards to member function)
export void swap(Truckload& one, Truckload& other) noexcept;
