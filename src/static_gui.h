#ifndef _STATIC_GUI_H_
#define _STATIC_GUI_H_

#include "SFML/Graphics.hpp"
#include "entity.h"
#include "resources.h"
#include "rounded_rect.h"

class StaticGUI : public Entity
{
  public:
  explicit StaticGUI(Resources &r);
  void render(sf::RenderTarget &t) override;

  private:
  Resources &resources;
  RoundedRect title_rect{};
  RoundedRect battle_area_rect{};
  RoundedRect player_info_rect{};
  RoundedRect enemy_info_rect{};
  RoundedRect inventory_rect{};
  sf::Text title_text;
  sf::Text player_hp_text;
  sf::Text player_fever_text;
  sf::Text player_xp_text;
  sf::Text enemy_hp_text;
  sf::Text inventory_text;
  sf::Sprite coin_icon;
};

#endif // !_STATIC_GUI_H_
