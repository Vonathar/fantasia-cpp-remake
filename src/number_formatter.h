#ifndef _NUMBER_FORMATTER_H_
#define _NUMBER_FORMATTER_H_

#include <iostream>

/**
 * A class responsible for formatting numbers to strings.
 */
class NumberFormatter
{
  public:
  /**
   * Returns a more readable representation of a long number.
   *
   * A maximum of two digits are allowed in the output string, and values are
   * rounded up whenever applicable. For values greater than 1 × 10^18 (one
   * quintillion), the value itself is returned.
   *
   * \example
   * abbreviate(123456) // returns "123.46k";
   *
   * @param n the number to be formatted.
   * @return the formatted input number.
   */
  static std::string abbreviate(const long double &n);
};

#endif //_NUMBER_FORMATTER_H_
