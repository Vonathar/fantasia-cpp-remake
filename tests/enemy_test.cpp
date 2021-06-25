#define private public

#include "../src/entities/enemy.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Enemy receives damage", "[enemy]")
{
  Resources r{};
  Enemy enemy{r};
  enemy.receive_damage(5);
  REQUIRE(enemy.hp == enemy.max_hp - 5);
}

TEST_CASE("Enemy dies when health is below 0", "[enemy]")
{
  Resources r{};
  Enemy enemy{r};
  enemy.receive_damage(enemy.max_hp + 1);
  REQUIRE(enemy.is_dead());
}

TEST_CASE("Enemy regenerates correctly", "[enemy]")
{
  Resources r{};
  Enemy enemy{r};
  enemy.regenerate(StageName::GREEN_FOREST, 1, false);
  REQUIRE_FALSE(enemy.is_dead());
  REQUIRE_FALSE(enemy.is_regenerating());
  REQUIRE(enemy.hp == enemy.max_hp);
  REQUIRE((enemy.level >= 1 && enemy.level <= 3));
}
