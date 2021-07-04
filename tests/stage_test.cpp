#include <catch2/catch_test_macros.hpp>

#define private public

#include "../src/entities/stage.h"

namespace stage_test
{
std::unique_ptr<sf::RenderWindow> w = std::make_unique<sf::RenderWindow>(
    sf::VideoMode(1, 1, 32), "t", sf::Style::None);
Resources r{};

TEST_CASE("Next stage is not unlocked if the boss has not been killed",
          "[stage]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE; i++)
    stage.record_enemy_death(false);

  REQUIRE_FALSE(stage.is_next_level_unlocked());
}

TEST_CASE("Next stage remains locked if more enemies are killed while the boss "
          "is available",
          "[stage]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE + 3; i++)
    stage.record_enemy_death(false);

  REQUIRE_FALSE(stage.is_next_level_unlocked());
}

TEST_CASE("Next stage is locked if the boss was not killed", "[stage]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE - 1; i++)
    stage.record_enemy_death(false);

  REQUIRE_FALSE(stage.is_boss_available());
}

TEST_CASE("Next stage is unlocked after the boss is killed", "[stage]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE; i++)
    stage.record_enemy_death(false);

  stage.record_enemy_death(true);

  REQUIRE(stage.is_next_level_unlocked());
}

TEST_CASE("Boss is not available anymore after it's killed", "[stage]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE; i++)
    stage.record_enemy_death(false);

  stage.record_enemy_death(true);

  REQUIRE_FALSE(stage.is_boss_available());
}

TEST_CASE("Boss cannot be unlocked more than once in the same stage", "[stage]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE; i++)
    stage.record_enemy_death(false);

  stage.record_enemy_death(true);

  for (int i = 0; i < stage.ENEMIES_PER_STAGE; i++)
    stage.record_enemy_death(false);

  REQUIRE_FALSE(stage.is_boss_available());
}

TEST_CASE("Incrementing the level resets number of enemies left", "[stage]")
{
  StageGUI gui{r};
  Stage stage{r};

  stage.increment_level();

  REQUIRE(stage.enemies_left == stage.ENEMIES_PER_STAGE);
}

TEST_CASE("When incrementing the level, the boss should not be available",
          "[stage]")
{
  StageGUI gui{r};
  Stage stage{r};

  stage.increment_level();

  REQUIRE_FALSE(stage.is_boss_available());
}

TEST_CASE("When an enemy is killed, the GUI counter should be updated",
          "[stage][integration]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE - 1; i++)
  {
    stage.record_enemy_death(false);
    auto expected_value = stage.ENEMIES_PER_STAGE - stage.enemies_left;
    auto actual_value = std::stoi(
        stage.gui.enemy_counter.text.getString().toAnsiString().substr(0, 1));
    REQUIRE(expected_value == actual_value);
  }
}

TEST_CASE("When the boss is unlocked, the GUI should display the button to "
          "start the boss fight",
          "[stage][integration]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE; i++)
    stage.record_enemy_death(false);

  stage.record_enemy_death(true);

  auto expected_string = "Fight boss?";
  auto actual_string = stage.gui.boss_button.text.getString().toAnsiString();

  REQUIRE(expected_string == actual_string);
}

TEST_CASE("When the boss fight is active, the GUI should display the button to "
          "quit the fight",
          "[stage][integration]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE; i++)
    stage.record_enemy_death(false);

  stage.record_enemy_death(true);
  stage.set_boss_fight(true);

  auto expected_string = "Quit fight?";
  auto actual_string = stage.gui.boss_button.text.getString().toAnsiString();

  REQUIRE(expected_string == actual_string);
}

TEST_CASE("When quitting the boss fight, the GUI should display the button to "
          "start it again",
          "[stage][integration]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE; i++)
    stage.record_enemy_death(false);

  stage.record_enemy_death(true);
  stage.set_boss_fight(true);
  stage.set_boss_fight(false);

  auto expected_string = "Fight boss?";
  auto actual_string = stage.gui.boss_button.text.getString().toAnsiString();

  REQUIRE(expected_string == actual_string);
}

TEST_CASE(
    "When the next stage is a multiple of 10, the stage name should advance",
    "[stage][integration]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < 10; i++)
    stage.increment_level();

  REQUIRE(StageName(1) == stage.get_name());
}

TEST_CASE(
    "When the stage name advances, the background image should also change",
    "[stage][integration]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < 10; i++)
    stage.increment_level();

  REQUIRE(&r.get_texture(StageName(1)) == stage.sprite.getTexture());
}

TEST_CASE("When unlocking a new level, the GUI should be updated",
          "[stage][integration]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE; i++)
    stage.record_enemy_death(false);

  stage.record_enemy_death(true);

  auto next_level_status = stage.gui.get_next_level().get_status();
  REQUIRE(next_level_status == StageLevelStatus::UNLOCKED);
}

TEST_CASE(
    "When incrementing level, the next level should be selected in the GUI",
    "[stage][integration]")
{
  StageGUI gui{r};
  Stage stage{r};

  int initial_next_level = stage.gui.get_next_level().value;
  stage.increment_level();
  int final_next_level = stage.gui.get_next_level().value;

  REQUIRE(initial_next_level != final_next_level);
}

TEST_CASE("When incrementing level, the following level should should be "
          "locked the GUI",
          "[stage][integration]")
{
  StageGUI gui{r};
  Stage stage{r};

  for (int i = 0; i < stage.ENEMIES_PER_STAGE; i++)
    stage.record_enemy_death(false);

  stage.record_enemy_death(true);

  stage.increment_level();
  int next_level_status = stage.gui.get_next_level().status;

  REQUIRE(next_level_status == StageLevelStatus::LOCKED);
}

} // namespace stage_test