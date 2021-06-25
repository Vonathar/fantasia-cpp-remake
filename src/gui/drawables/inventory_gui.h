#ifndef _INVENTORY_GUI_H_
#define _INVENTORY_GUI_H_

#include "../resources.h"

class InventoryGUI : public sf::Drawable
{
  public:
  explicit InventoryGUI(Resources &r);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void set_money(long double money);

  private:
  Resources &resources;
  sf::Text money_text;
};

#endif //_INVENTORY_GUI_H_
