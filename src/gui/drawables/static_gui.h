#ifndef _STATIC_GUI_H_
#define _STATIC_GUI_H_

#include "../resources.h"
#include "SFML/Graphics.hpp"
#include "reusable/rounded_rect.h"

class StaticGUI : public sf::Drawable
{
  public:
  explicit StaticGUI(Resources &r);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  private:
  Resources &resources;
  RoundedRect title_rect{};
  RoundedRect battle_area_rect{};
  RoundedRect player_info_rect{};
  RoundedRect enemy_info_rect{};
  RoundedRect inventory_rect{};
  sf::Text title_text;
  sf::Text auto_progress_text{};
  sf::Text player_hp_text;
  sf::Text player_fever_text;
  sf::Text player_xp_text;
  sf::Text enemy_hp_text;
  sf::Text inventory_text;
  sf::Sprite coin_icon;
};

#endif // !_STATIC_GUI_H_
