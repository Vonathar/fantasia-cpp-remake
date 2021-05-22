#include "enemy_gui.h"

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

void EnemyGUI::render(sf::RenderTarget &target)
{
  target.draw(hp_bar);
  target.draw(info);
}
