#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include "../gui/drawables/inventory_gui.h"
#include "../gui/resources.h"

class Inventory : public sf::Drawable
{
  public:
  explicit Inventory(Resources &r);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void add_money(long double &m);

  private:
  Resources &resources;
  InventoryGUI gui;
  long double money;
};

#endif //_INVENTORY_H_
