#include "inventory.h"

Inventory::Inventory(Resources &r) : resources(r), gui(r)
{
  money = 0;
  gui.set_money(money);
}

void Inventory::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(gui);
}

void Inventory::add_money(long double &m)
{
  money += m;
  gui.set_money(money);
}