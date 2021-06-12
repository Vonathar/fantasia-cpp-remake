#include "inventory.h"

Inventory::Inventory(Resources &r) : resources(r), gui(r)
{
  money = 0;
  gui.set_money(money);
}

void Inventory::render(sf::RenderTarget &target)
{
  gui.render(target);
}

void Inventory::add_money(long double &m)
{
  money += m;
  gui.set_money(money);
}