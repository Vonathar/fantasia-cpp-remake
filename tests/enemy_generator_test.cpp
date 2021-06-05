#define private public

#include "../src/enemy_generator.h"
#include <algorithm>
#include <catch2/catch.hpp>

TEST_CASE("Returns a random enemy for the given stage", "[enemy_generator]")
{
  EnemyGenerator enemy_generator{};

  for (int i = 0; i <= static_cast<int>(StageName::INFERNO); i++)
  {
    auto stage = static_cast<StageName>(i);
    EnemyName enemy = enemy_generator.get_random_enemy(stage);
    std::vector<EnemyName> enemies = enemy_generator.stage_enemies[stage];
    REQUIRE(std::find(enemies.begin(), enemies.end(), enemy) != enemies.end());
  }
}

TEST_CASE("Returns a random boss for the given stage", "[enemy_generator]")
{
  EnemyGenerator enemy_generator{};

  for (int i = 0; i <= static_cast<int>(StageName::INFERNO); i++)
  {
    auto stage = static_cast<StageName>(i);
    EnemyName boss = enemy_generator.get_random_boss(stage);
    std::vector<EnemyName> bosses = enemy_generator.stage_bosses[stage];
    REQUIRE(std::find(bosses.begin(), bosses.end(), boss) != bosses.end());
  }
}