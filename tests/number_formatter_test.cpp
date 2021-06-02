#include "../src/number_formatter.h"
#include <catch2/catch.hpp>

NumberFormatter number_formatter{};

TEST_CASE("Numbers are formatted", "[number_formatter]")
{
  REQUIRE(number_formatter.abbreviate(100) == "100");
  REQUIRE(number_formatter.abbreviate(1'000) == "1.00k");
  REQUIRE(number_formatter.abbreviate(999'999) == "999.99k");
  REQUIRE(number_formatter.abbreviate(1'000'000) == "1.00m");
  REQUIRE(number_formatter.abbreviate(999'999'999) == "999.99m");
  REQUIRE(number_formatter.abbreviate(1'000'000'000) == "1.00b");
  REQUIRE(number_formatter.abbreviate(999'999'999'999) == "999.99b");
  REQUIRE(number_formatter.abbreviate(1'000'000'000'000) == "1.00t");
  REQUIRE(number_formatter.abbreviate(999'999'999'999'999) == "999.99t");
  REQUIRE(number_formatter.abbreviate(1'000'000'000'000'000) == "1.00Qa");
  REQUIRE(number_formatter.abbreviate(999'999'999'999'999'999) == "999.99Qa");
}