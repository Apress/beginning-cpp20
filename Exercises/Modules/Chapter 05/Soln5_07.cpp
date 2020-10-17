// Exercise 5-7. Outputting product records & cost
// Getting the alignment right is tricky.
// You have to adjust the field widths until it looks OK.
import <iostream>;
import <format>;
import <vector>;

#include <cctype>

int main()
{
  std::vector<size_t> product_id;
  std::vector<size_t> quantity;
  std::vector<double> unit_cost;

  // Read the records
  while (true)
  {
    std::cout << "Enter a record - product number, quantity, unit cost separated by spaces: ";
    size_t id {};
    size_t n {};
    double cost {};
    std::cin >> id >> n >> cost;

    product_id.push_back(id);
    quantity.push_back(n);
    unit_cost.push_back(cost);
    
    std::cout << "Do you want to enter another record (Y or N): ";
    char answer {};
    std::cin >> answer;
    if (std::toupper(answer) == 'N') break;
  }
  
  // Column headings
  std::cout << std::format("{:10} {:10} {:10} {:10}\n", 
    "Product", "Quantity", "Unit Price", "Cost");
  
  double total_cost {};
  for (size_t i {}; i < product_id.size(); ++i)
  {
    const auto cost{ quantity[i] * unit_cost[i] };
    
    std::cout <<
      std::format("{:<10} {:<10} ${:<9.2f} ${:<9.2f}\n",
        product_id[i], quantity[i], unit_cost[i], cost);
    
    total_cost += cost;
  }
  // Note the little trick to add empty space...
  std::cout << std::format("{:33}${:<9.2f}\n", "", total_cost);
}