#include "number_formatter.h"
#include <cmath>
#include <iomanip>
#include <sstream>

std::string NumberFormatter::abbreviate(const long double &n)
{
  std::stringstream output;

  // 0 - 999
  if (n < 1000)
  {
    output << std::fixed << std::setprecision(0);
    output << (n);
    return output.str();
  }

  output << std::fixed << std::setprecision(2);

  // 1k - 999k
  if (n >= 1'000 && n < 1'000'000)
  {
    output << std::floor((n / 1'000) * 100) / 100 << "k";
  }
  // 1m - 999m
  else if (n >= 1'000'000 && n < 1'000'000'000)
  {
    output << std::floor((n / 1'000'000) * 100) / 100 << "m";
  }
  // 1b - 999b
  else if (n >= 1'000'000'000 && n < 1'000'000'000'000)
  {
    output << std::floor((n / 1'000'000'000) * 100) / 100 << "b";
  }
  // 1t - 999t
  else if (n >= 1'000'000'000'000 && n < 1'000'000'000'000'000)
  {
    output << std::floor((n / 1'000'000'000'000) * 100) / 100 << "t";
  }
  // 1Qa - 999Qa
  else if (n >= 1'000'000'000'000'000 && n < 1'000'000'000'000'000'000)
  {
    output << std::floor((n / 1'000'000'000'000'000) * 100) / 100 << "Qa";
  }
  else if (n > 1'000'000'000'000'000'000)
  {
    output << (n);
  }

  return output.str();
}