#include "stage_gui.h"
#include "cmath"

StageGUI::StageGUI(Resources &r) : resources(r)
{
  main_rect.set_size(sf::Vector2f(320.0f, 165.0f));
  main_rect.set_corners_radius(25);
  main_rect.set_corner_point_count(50);
  main_rect.setFillColor(sf::Color(0, 0, 0, 230));
  main_rect.setPosition(800.0f, 300.0f);

  level_rect_1.set_status(StageLevelStatus::ACTIVE);
  level_rect_2.set_status(StageLevelStatus::LOCKED);
  level_rect_3.set_status(StageLevelStatus::LOCKED);
  level_rect_4.set_status(StageLevelStatus::LOCKED);
  level_rect_5.set_status(StageLevelStatus::LOCKED);

  stage_name_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  stage_name_text.setCharacterSize(14);
  stage_name_text.setFillColor(sf::Color(255, 255, 255, 230));
  stage_name = StageName::GREEN_FOREST;
  set_stage_name_text(stage_name);
}

void StageGUI::set_stage_name_text(const StageName n)
{
  stage_name_text.setString(resources.get_name(n));
  sf::FloatRect rect_bounds = stage_name_text.getLocalBounds();
  float text_pos_x = 960 - std::floor(rect_bounds.width / 2);
  stage_name_text.setPosition(text_pos_x, 370.0f);
}

void StageGUI::set_next_level_unlocked()
{
  get_next_level().set_status(StageLevelStatus::UNLOCKED);
  enemy_counter.set_visible(false);
  boss_button.set_visible(false);
}

void StageGUI::set_enemies_killed(int n)
{
  enemies_killed = n;

  if (enemies_killed == 5)
  {
    boss_button.set_boss_available();
    boss_button.set_visible(true);
    enemy_counter.set_visible(false);
  }

  else
    enemy_counter.set_enemies_killed(n);
}

void StageGUI::set_boss_fight(bool bf)
{
  boss_fight = bf;

  if (boss_fight)
    boss_button.set_boss_active();
  else
    boss_button.set_boss_available();
}

sf::FloatRect StageGUI::get_next_level_bounds()
{
  return get_next_level().get_bounds();
}

sf::FloatRect StageGUI::get_boss_button_bounds()
{
  return boss_button.get_bounds();
}

StageLevel &StageGUI::get_next_level()
{
  if (level_rect_1.get_status() == StageLevelStatus::ACTIVE)
    return level_rect_2;

  else if (level_rect_2.get_status() == StageLevelStatus::ACTIVE)
    return level_rect_3;

  else
    return level_rect_4;
}

void StageGUI::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(main_rect);
  target.draw(stage_name_text);
  target.draw(level_rect_1);
  target.draw(level_rect_2);
  target.draw(level_rect_3);
  target.draw(level_rect_4);
  target.draw(level_rect_5);
  target.draw(enemy_counter);
  target.draw(boss_button);
}

void StageGUI::set_next_level_selected()
{
  boss_button.set_visible(false);
  enemy_counter.set_visible(true);

  if (level_rect_3.get_value() == 3 &&
      level_rect_3.get_status() != StageLevelStatus::ACTIVE)
  {
    if (level_rect_1.get_status() == StageLevelStatus::ACTIVE)
    {
      level_rect_1.set_status(StageLevelStatus::COMPLETED);
      level_rect_2.set_status(StageLevelStatus::ACTIVE);
    }
    else if (level_rect_2.get_status() == StageLevelStatus::ACTIVE)
    {
      level_rect_2.set_status(StageLevelStatus::COMPLETED);
      level_rect_3.set_status(StageLevelStatus::ACTIVE);
    }
  }

  else
  {
    level_rect_1.increment_value();
    level_rect_2.increment_value();
    level_rect_3.increment_value();
    level_rect_4.increment_value();
    level_rect_5.increment_value();

    level_rect_2.set_status(StageLevelStatus::COMPLETED);
    level_rect_3.set_status(StageLevelStatus::ACTIVE);
    level_rect_4.set_status(StageLevelStatus::LOCKED);
  }
}
