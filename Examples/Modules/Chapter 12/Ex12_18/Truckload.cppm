export module truckload;
import box;

import <memory>;
import <vector>;

export using SharedBox = std::shared_ptr<Box>;

export class Truckload
{
public:
  Truckload() = default;            // Default constructor - empty truckload

  Truckload(SharedBox box);         // Constructor - one Box
  Truckload(const std::vector<SharedBox>& boxes);  // Constructor - vector of Boxes
  Truckload(const Truckload& src);  // Copy constructor

  ~Truckload();                     // Destructor

  SharedBox getFirstBox();          // Get the first Box
  SharedBox getNextBox();           // Get the next Box
  void addBox(SharedBox box);       // Add a new SharedBox
  bool removeBox(SharedBox box);    // Remove a Box from the Truckload
  void listBoxes() const;           // Output the Boxes

private:
  class Package
  {
  public:
    SharedBox m_box;      // Pointer to the Box object contained in this Package
    Package* m_next;      // Pointer to the next Package in the list

    Package(SharedBox box) : m_box{ box }, m_next{ nullptr } {} // Constructor
    ~Package() { delete m_next; }                           // Destructor
  };

  Package* m_head {};               // First in the list
  Package* m_tail {};               // Last in the list
  Package* m_current {};            // Last retrieved from the list
};
