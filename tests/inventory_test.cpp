#define private public

#include "../src/entities/inventory.h"
#include <catch2/catch_test_macros.hpp>

namespace inventory_test
{
Resources r{};

TEST_CASE("Money is added correctly to the total", "[inventory]")
{
  Inventory inventory{r};
  long double value = 5;
  inventory.add_money(value);
  inventory.add_money(value);
  REQUIRE(inventory.money == 10);
}
} // namespace inventory_test