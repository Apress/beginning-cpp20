// Exercise 20-5 Create a generic average() algorithm using std::accumulate()
import <iostream>;
import <numeric>;
import <utility>;     // for std::pair<> (only required for Solution 2 below)
import <optional>;
import <vector>;

// Solution 1: simply use accumulate to sum, and determine the count using std::distance() 
// (the latter is more general than using iterator arithmetic, end - begin, 
// which only works for random-access iterators)
template <typename T, typename IterType>
std::optional<T> average(IterType begin, IterType end)
{
	const auto count{ std::distance(begin, end) };
	const auto sum{ std::accumulate(begin, end, T{}) };

	return count ? std::optional<T>{ sum / count } : std::nullopt;
}

// Solution 2: accumulate a pair<> that counts both the number of elements and the sum
//template <typename T, typename IterType>
//std::optional<T> average(IterType begin, IterType end)
//{
//  const auto accumulated { 
//    std::accumulate(begin, end, std::make_pair(0u, T{}), [](const auto& accumulated, const auto& element)
//    { 
//      return std::make_pair(accumulated.first + 1, accumulated.second + element); 
//    })
//	};
//
//  return accumulated.first ? std::optional<T>{ accumulated.second / accumulated.first } : std::nullopt;
//}


int main()
{
  std::vector<double> numbers{ 1, 2, 4, 8, 16, 32, 64, 128, 256 };
  std::cout << *average<double>(begin(numbers), end(numbers)) << std::endl;
}
