// Exercising capturing the this pointer
#include "Finder.h"
#include "Optimum.h"
#include <cmath>       // For std::abs()

std::optional<double> Finder::findNearest(const std::vector<double>& values) const
{
  if (values.empty())
    return std::nullopt;
  else  
    return *findOptimum(values, [this](double x, double y) {
      return std::abs(x - m_number_to_search_for) < std::abs(y - m_number_to_search_for);
    });
}

double Finder::getNumberToSearchFor() const
{
  return m_number_to_search_for;
}

void Finder::setNumberToSearchFor(double value)
{
  m_number_to_search_for = value;
}