#include "stage.h"

Stage::Stage(Resources &r) : resources(r)
{
  sprite.setPosition(0, 0);
  sprite.setScale(1.0f, 1.0f);
  sprite.setTexture(resources.get_texture(StageName::GREEN_FOREST));
  enemies_left = ENEMIES_PER_STAGE;
}

void Stage::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(sprite);
  target.draw(gui);
}

void Stage::record_enemy_death(bool is_boss)
{
  if (is_boss)
  {
    gui.set_next_level_unlocked();
    boss_available = false;
  }

  else if (enemies_left > 0)
  {
    --enemies_left;
    gui.set_enemies_killed(ENEMIES_PER_STAGE - enemies_left);

    if (enemies_left == 0)
      boss_available = true;
  }
}

void Stage::increment_level()
{
  ++level;
  enemies_left = ENEMIES_PER_STAGE;
  gui.set_next_level_selected();
  gui.set_enemies_killed(0);
  if (level % 10 == 0)
    increment_stage();
}

void Stage::set_boss_fight(bool boss_fight)
{
  gui.set_boss_fight(boss_fight);
}

void Stage::increment_stage()
{
  name = StageName((int)name + 1);
  sprite.setTexture(resources.get_texture(name));
}

const StageName &Stage::get_name()
{
  return name;
}

bool Stage::is_next_level_unlocked() const
{
  return enemies_left == 0 && !boss_available;
}

bool Stage::is_next_level_in_bounds(sf::Vector2f &pos)
{
  return gui.get_next_level_bounds().contains(pos);
}

bool Stage::is_boss_button_in_bounds(sf::Vector2f &pos)
{
  return gui.get_boss_button_bounds().contains(pos);
}

const int &Stage::get_level() const
{
  return level;
}

const bool &Stage::is_boss_available() const
{
  return boss_available;
}
