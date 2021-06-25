#include <catch2/catch_test_macros.hpp>

#define private public

#include "../src/gui/drawables/stage/stage_gui.h"

namespace stage_gui_test
{
Resources r{};

TEST_CASE("When the last enemy is killed, the enemy counter is disabled",
          "[stage_gui][integration]")
{
  StageGUI gui{r};

  gui.enemy_counter.visible = true;
  gui.set_enemies_killed(5);

  REQUIRE_FALSE(gui.enemy_counter.visible);
}

TEST_CASE("When the last enemy is killed, the boss button is enabled",
          "[stage_gui][integration]")
{
  StageGUI gui{r};

  gui.boss_button.visible = false;
  gui.set_enemies_killed(5);

  REQUIRE(gui.boss_button.visible);
}

TEST_CASE("When the last enemy is killed, the boss button displays the correct "
          "text",
          "[stage_gui][integration]")
{
  StageGUI gui{r};

  gui.set_enemies_killed(5);

  REQUIRE(gui.boss_button.text.getString().toAnsiString() == "Fight boss?");
}

TEST_CASE("The bounds of the boss button are correctly returned",
          "[stage_gui][integration]")
{
  StageGUI gui{r};

  REQUIRE(gui.get_boss_button_bounds() ==
          gui.boss_button.rect.getGlobalBounds());
}

TEST_CASE("The bounds of the enemy counter are correctly returned",
          "[stage_gui][integration]")
{
  StageGUI gui{r};

  REQUIRE(gui.get_next_level_bounds() ==
          gui.get_next_level().rect.getGlobalBounds());
}

} // namespace stage_gui_test
