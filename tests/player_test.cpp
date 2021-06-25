#define private public

#include "../src/entities/player.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Player receives damage", "[player]")
{
  Resources r{};
  Player player{r};
  player.receive_damage(5);
  REQUIRE(player.hp == player.max_hp - 5);
}

TEST_CASE("Player dies when health is below 0", "[player]")
{
  Resources r{};
  Player player{r};
  player.receive_damage(player.max_hp + 1);
  REQUIRE(player.is_dead());
}

TEST_CASE("Player receives xp", "[player]")
{
  Resources r{};
  Player player{r};
  player.receive_xp(5);
  REQUIRE(player.xp == 5);
}

TEST_CASE("Player level increases when required xp is reached", "[player]")
{
  Resources r{};
  Player player{r};
  player.receive_xp(player.required_xp);
  REQUIRE(player.level == 2);
}

TEST_CASE("Player doesn't lose excess xp when level increases", "[player]")
{
  Resources r{};
  Player player{r};
  player.receive_xp(player.required_xp + 1);
  REQUIRE(player.xp == 1);
}

TEST_CASE("Player regenerates correctly", "[player]")
{
  Resources r{};
  Player player{r};
  player.regenerate();
  REQUIRE_FALSE(player.is_dead());
  REQUIRE_FALSE(player.is_regenerating());
  REQUIRE(player.hp == player.max_hp);
  REQUIRE(player.fever == 0);
}