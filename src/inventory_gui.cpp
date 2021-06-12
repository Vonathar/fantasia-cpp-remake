#include "inventory_gui.h"

InventoryGUI::InventoryGUI(Resources &r) : resources(r)
{
  money_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  money_text.setCharacterSize(17);
  money_text.setFillColor(sf::Color::White);
  money_text.setLetterSpacing(0.5f);
}

void InventoryGUI::set_money(long double money)
{
  money_text.setString(std::to_string(static_cast<long long>(money)));
  sf::FloatRect info_bounds = money_text.getLocalBounds();
  money_text.setPosition(1633.0f - info_bounds.width / 2, 285.0f);
}

void InventoryGUI::render(sf::RenderTarget &target)
{
  target.draw(money_text);
}