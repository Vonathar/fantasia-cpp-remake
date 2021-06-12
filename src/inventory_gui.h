#ifndef _INVENTORY_GUI_H_
#define _INVENTORY_GUI_H_

#include "entity.h"
#include "resources.h"

class InventoryGUI : public Entity
{
  public:
  explicit InventoryGUI(Resources &r);
  void render(sf::RenderTarget &target) override;
  void set_money(long double money);

  private:
  Resources &resources;
  sf::Text money_text;
};

#endif //_INVENTORY_GUI_H_
