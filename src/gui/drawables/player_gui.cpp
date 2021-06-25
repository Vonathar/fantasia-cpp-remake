#include "player_gui.h"

PlayerGUI::PlayerGUI(Resources &r) : resources(r)
{
  info.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  info.setCharacterSize(17);
  info.setFillColor(sf::Color::White);
  info.setLetterSpacing(0.5f);
  fever_bar.set_max_value(100);
}

void PlayerGUI::set_info(const std::string &rank, int level)
{
  info.setString("Lv. " + std::to_string(level) + " " + rank);
  sf::FloatRect player_info_bounds = info.getLocalBounds();
  info.setPosition(697.0f - player_info_bounds.width / 2, 832.0f);
}

void PlayerGUI::set_hp(double hp)
{
  hp_bar.set_value(static_cast<float>(hp));
}

void PlayerGUI::set_max_hp(double max_hp)
{
  hp_bar.set_max_value(static_cast<float>(max_hp));
}

void PlayerGUI::set_xp(double xp)
{
  xp_bar.set_value(static_cast<float>(xp));
}

void PlayerGUI::set_required_xp(double max_xp)
{
  xp_bar.set_max_value(static_cast<float>(max_xp));
}

void PlayerGUI::set_fever(double fever)
{
  fever_bar.set_value(static_cast<float>(fever));
}

void PlayerGUI::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(hp_bar);
  target.draw(xp_bar);
  target.draw(fever_bar);
  target.draw(info);
}