#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include "entity.h"
#include "inventory_gui.h"
#include "resources.h"

class Inventory : public Entity
{
  public:
  Inventory(Resources &r);
  void render(sf::RenderTarget &target) override;
  void add_money(long double &m);

  private:
  Resources &resources;
  InventoryGUI gui;
  long double money;
};

#endif //_INVENTORY_H_
