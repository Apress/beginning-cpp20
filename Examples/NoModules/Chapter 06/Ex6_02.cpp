// Dereferencing pointers
// Calculates the purchase price for a given quantity of items
#include <iostream>
#include <format>

int main()
{
  int unit_price {295};                // Item unit price in cents
  int count {};                        // Number of items ordered
  int discount_threshold {25};         // Quantity threshold for discount
  double discount {0.07};              // Discount for quantities over discount_threshold

  int* pcount {&count};                // Pointer to count
  std::cout << "Enter the number of items you want: ";
  std::cin >> *pcount;
  std::cout << std::format("The unit price is ${:.2f}\n", unit_price / 100.0);

  // Calculate gross price
  int* punit_price{ &unit_price };      // Pointer to unit_price
  int price{ *pcount * *punit_price };  // Gross price via pointers
  auto* pprice {&price};                // Pointer to gross price

  // Calculate net price in US$
  double net_price{};
  double* pnet_price {nullptr};
  pnet_price = &net_price;
  if (*pcount > discount_threshold)
  {
    std::cout << 
      std::format("You qualify for a discount of {:.0f} percent.\n", discount * 100);
    *pnet_price = price*(1 - discount) / 100;
  }
  else
  {
    net_price = *pprice / 100;
  }
  std::cout << std::format("The net price for {} items is ${:.2f}\n", *pcount, net_price);
}
