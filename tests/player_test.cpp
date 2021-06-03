#include "../src/player.h"
#include <catch2/catch.hpp>

Resources r{};

TEST_CASE("Player receives damage", "[player]")
{
  Player player{r};
  player.receive_damage(5);
  REQUIRE(player.get_hp() == player.get_max_hp() - 5);
}

TEST_CASE("Player dies when health is below 0", "[player]")
{
  Player player{r};
  player.receive_damage(player.get_max_hp() + 1);
  REQUIRE(player.is_dead());
}

TEST_CASE("Player receives xp", "[player]")
{
  Player player{r};
  player.receive_xp(5);
  REQUIRE(player.get_xp() == 5);
}

TEST_CASE("Player level increases when required xp is reached", "[player]")
{
  Player player{r};
  player.receive_xp(player.get_required_xp());
  REQUIRE(player.get_level() == 2);
}

TEST_CASE("Player doesn't lose excess xp when level increases", "[player]")
{
  Player player{r};
  player.receive_xp(player.get_required_xp() + 1);
  REQUIRE(player.get_xp() == 1);
}

TEST_CASE("Player regenerates correctly", "[player]")
{
  Player player{r};
  player.regenerate();
  REQUIRE_FALSE(player.is_dead());
  REQUIRE_FALSE(player.is_regenerating());
  REQUIRE(player.get_hp() == player.get_max_hp());
  REQUIRE(player.get_fever() == 0);
}