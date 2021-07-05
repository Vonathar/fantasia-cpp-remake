#include "inventory_gui.h"

InventoryGUI::InventoryGUI(Resources &r) : resources(r)
{
  money_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  money_text.setCharacterSize(16);
  money_text.setFillColor(sf::Color::White);
}

void InventoryGUI::set_money(long double money)
{
  money_text.setString(std::to_string(static_cast<long long>(money)));
  sf::FloatRect info_bounds = money_text.getLocalBounds();
  float pos_x = 1633.0f - (float)int(info_bounds.width / 2);
  money_text.setPosition(pos_x, 285.0f);
}

void InventoryGUI::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(money_text);
}