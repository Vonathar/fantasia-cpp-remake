#include "enemy_gui.h"
#include <cmath>

EnemyGUI::EnemyGUI(Resources &r) : resources(r)
{
  info.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  info.setCharacterSize(17);
  info.setFillColor(sf::Color::White);
  info.setLetterSpacing(0.5f);
}

void EnemyGUI::set_max_hp(double max_hp)
{
  hp_bar.set_max_value(static_cast<float>(max_hp));
}

void EnemyGUI::set_hp(double hp)
{
  hp_bar.set_value(static_cast<float>(hp));
}

void EnemyGUI::set_info(const std::string &name, int level)
{
  info.setString("Lv. " + std::to_string(level) + " " + name);
  sf::FloatRect enemy_info_bounds = info.getLocalBounds();
  info.setPosition(1098.0f - enemy_info_bounds.width / 2, 832.0f);
}

void EnemyGUI::set_texture(const sf::Texture &texture)
{
  sprite.setTexture(texture, true);
  sprite.setOrigin(sprite.getLocalBounds().width / 2,
                   sprite.getLocalBounds().height /
                   (2 * std::pow(sprite.getLocalBounds().height, -0.082)));
  sprite.setPosition(1095.0f, 760.0f);
  sprite.setScale(0.8f, 0.8f);
}

void EnemyGUI::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(hp_bar);
  target.draw(info);
  target.draw(sprite);
}

sf::Sprite &EnemyGUI::get_sprite()
{
  return sprite;
}

bool EnemyGUI::boundaries_contain(sf::Vector2f &pos)
{
  return sprite.getGlobalBounds().contains(pos);
}
