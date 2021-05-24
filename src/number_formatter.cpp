#include "number_formatter.h"
#include <iomanip>
#include <sstream>

std::string NumberFormatter::abbreviate(const long double &n)
{
  std::stringstream output;

  // 0 - 999
  if (n < 1000)
  {
    output << (n);
    return output.str();
  }
  // 1k - 999k
  if (n >= 1'000 && n < 1'000'000)
  {
    output << std::fixed << std::setprecision(2);
    output << (n / 1'000);
    return output.str() + "k";
  }
  // 1m - 999m
  if (n >= 1'000'000 && n < 1'000'000'000)
  {
    output << std::fixed << std::setprecision(2);
    output << (n / 1'000'000);
    return output.str() + "m";
  }
  // 1b - 999b
  if (n >= 1'000'000'000 && n < 1'000'000'000'000)
  {
    output << std::fixed << std::setprecision(2);
    output << (n / 1000000000);
    return output.str() + "b";
  }
  // 1t - 999t
  if (n >= 1'000'000'000'000 && n < 1'000'000'000'000'000)
  {
    output << std::fixed << std::setprecision(2);
    output << (n / 1'000'000'000'000);
    return output.str() + "t";
  }
  // 1Qa - 999Qa
  if (n >= 1'000'000'000'000'000 && n < 1'000'000'000'000'000'000)
  {
    output << std::fixed << std::setprecision(2);
    output << (n / 1'000'000'000'000'000);
    return output.str() + "Qa";
  }
  if (n > 1'000'000'000'000'000'000)
  {
    output << (n);
    return output.str();
  }
}