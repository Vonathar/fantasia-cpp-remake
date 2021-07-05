#include "stage_enemy_counter.h"

StageEnemyCounter::StageEnemyCounter(Resources &r) : resources(r)
{
  sprite.setTexture(resources.get_texture(ResourceName::PIERCED_SKULL_TEXTURE));
  sprite.setPosition(930.0f, 410.0f);
  sprite.setScale(0.7f, 0.7f);

  text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  text.setPosition(960.0f, 412.0f);
  text.setCharacterSize(14);
  text.setFillColor(sf::Color(255, 255, 255, 230));
  set_enemies_killed(0);

  visible = true;
}

void StageEnemyCounter::set_enemies_killed(int n)
{
  text.setString(std::to_string(n) + " / 5");
}

void StageEnemyCounter::draw(sf::RenderTarget &target,
                             sf::RenderStates states) const
{
  if (visible)
  {
    target.draw(sprite);
    target.draw(text);
  }
}

void StageEnemyCounter::set_visible(bool v)
{
  visible = v;
}
