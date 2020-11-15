// Exercise 21-3 
import <iostream>;
import <concepts>;
import <span>;
import <array>;
import <string>;

/* Not requested, but just for fun, here is a concept that prescribes 
   a complete set of operations one would require to take an average */
template <typename T>
concept Averagable = requires (const T x, const T y, T z, const int i)
{
  { x + y }  -> std::same_as<T>;
  { x - y }  -> std::same_as<T>;
  { z += y } -> std::same_as<T&>;
  { z -= y } -> std::same_as<T&>;
  { x / i }  -> std::same_as<T>;
  { x * i }  -> std::same_as<T>;
  { z /= i } -> std::same_as<T&>;
  { z *= i } -> std::same_as<T&>;
};

// By default, take the N / 2'th element
// (Note: this template covers both the case if T would not be Averageble,
//  and the case where N % 2 == 1).
template <typename T, size_t N>
auto& medianOfSorted(std::span<T, N> span)
{
  static_assert(N != 0, "The median of an empty span is not defined");
  return span[N / 2];
}

template <Averagable T, size_t N> requires (N % 2 == 0)
auto medianOfSorted(std::span<T, N> span)
{
  static_assert(N != 0, "The median of an empty span is not defined");
  return (span[N / 2 - 1] + span[N / 2]) / 2;
}

int main()
{
  std::array values_odd{ 1, 2, 3, 4, 5, 6, 7 };
  std::cout << medianOfSorted(std::span{ values_odd }) << std::endl;

  std::array values_even{ 1., 2., 3., 4., 5., 6. };
  std::cout << medianOfSorted(std::span{ values_even }) << std::endl;

  std::string strings_odd[] { "1", "2", "3", "4", "5" };
  std::cout << medianOfSorted(std::span{ strings_odd }) << std::endl;

  std::string strings_even[] { "1", "2", "3", "4", "5", "6" };
  std::cout << medianOfSorted(std::span{ strings_even }) << std::endl;
}