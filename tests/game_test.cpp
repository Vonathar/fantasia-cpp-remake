#include <catch2/catch_test_macros.hpp>

#define private public

#include "../src/game.h"

namespace game_test
{

TEST_CASE("The boss button is clicked", "[game][integration]")
{
  Game g{};

  SECTION("The boss is not available")
  {
    g.enemy.boss = false;
    g.stage.boss_available = false;

    SECTION("The current enemy should not be replaced by a boss")
    {
      g.handle_boss_button_click();
      REQUIRE(!g.enemy.is_boss());
    }

    SECTION("The current enemy should not be regenerated")
    {
      g.enemy.hp = 1;
      g.handle_boss_button_click();
      REQUIRE(g.enemy.hp == 1);
    }
  }

  SECTION("The boss is available")
  {
    g.stage.boss_available = true;

    SECTION("The current enemy is not a boss")
    {
      g.enemy.boss = false;
      g.stage.boss_available = true;

      SECTION("The text of the boss button should be updated")
      {
        g.handle_boss_button_click();
        REQUIRE(g.stage.gui.boss_button.text.getString() == "Quit fight?");
      }

      SECTION("The current enemy should be replaced by a boss")
      {
        g.handle_boss_button_click();
        REQUIRE(g.enemy.is_boss());
      }

      SECTION("The player's health should be set to its maximum")
      {
        g.player.hp = g.player.max_hp - 1;
        g.handle_boss_button_click();

        REQUIRE(g.player.hp == g.player.max_hp);
      }
    }

    SECTION("The current enemy is a boss")
    {
      g.enemy.boss = true;
      g.stage.boss_available = true;

      SECTION("The current boss should be replaced by a normal enemy")
      {
        g.handle_boss_button_click();
        REQUIRE(!g.enemy.is_boss());
      }

      SECTION("The boss button should be updated with the correct text")
      {
        g.handle_boss_button_click();
        REQUIRE(g.stage.gui.boss_button.text.getString() == "Fight boss?");
      }
    }
  }
}

TEST_CASE("The boss is killed", "[game][integration]")
{
  Game g{};
  g.stage.gui.enemy_counter.visible = true;
  g.stage.gui.boss_button.visible = true;
  g.stage.boss_available = true;

  g.handle_boss_button_click();
  g.stage.record_enemy_death(true);

  SECTION("The enemy counter and the boss button should be hidden from the GUI")
  {
    REQUIRE(!g.stage.gui.enemy_counter.visible);
    REQUIRE(!g.stage.gui.boss_button.visible);
  }

  SECTION("The boss fight should not be available")
  {
    REQUIRE(!g.stage.boss_available);
  }
}

TEST_CASE("The next level button in clicked", "[game][integration]")
{
  Game g{};

  SECTION("The next level is not unlocked")
  {
    g.stage.boss_available = false;
    g.stage.enemies_left = 5;

    SECTION("The level should not be increased")
    {
      g.stage.level = 1;
      g.handle_next_level_click();
      REQUIRE(g.stage.level == 1);
    }

    SECTION("The enemy should not be regenerated")
    {
      g.enemy.hp = 1;
      g.handle_next_level_click();
      REQUIRE(g.enemy.hp == 1);
    }

    SECTION("The GUI should not be updated")
    {
      g.stage.gui.get_next_level().value = 2;
      g.handle_next_level_click();
      REQUIRE(g.stage.gui.get_next_level().value == 2);
    }
  }

  SECTION("The next level is unlocked")
  {
    g.stage.boss_available = false;
    g.stage.enemies_left = 0;

    SECTION("The level should be increased")
    {
      g.stage.level = 1;
      g.handle_next_level_click();
      REQUIRE(g.stage.level == 2);
    }

    SECTION("The enemy should be regenerated")
    {
      g.enemy.hp = 1;
      g.handle_next_level_click();
      REQUIRE(g.enemy.hp == g.enemy.max_hp);
    }

    SECTION("The level in the GUI should be updated")
    {
      int initial_level = g.stage.gui.get_next_level().value;
      g.handle_next_level_click();
      REQUIRE(g.stage.gui.get_next_level().value == initial_level + 1);
    }

    SECTION("The stage button should be made visible, and the boss button "
            "should be hidden")
    g.stage.gui.boss_button.visible = true;
    g.stage.gui.enemy_counter.visible = false;
    g.stage.enemies_left = 0;
    g.handle_next_level_click();
    REQUIRE(g.stage.gui.boss_button.visible == false);
    REQUIRE(g.stage.gui.enemy_counter.visible == true);
  }
}

} // namespace game_test