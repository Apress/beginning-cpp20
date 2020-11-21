// Finder.cppm - A small class to illustrate the use of lambda expression in member functions
export module finder;

import <vector>;
import <optional>;

export class Finder
{
public:
  double getNumberToSearchFor() const;
  void setNumberToSearchFor(double n);

  std::optional<double> findNearest(const std::vector<double>& values) const;
private:
  double m_number_to_search_for {};
};
