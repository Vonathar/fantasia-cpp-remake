#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "SFML/Graphics.hpp"
#include "entity.h"
#include "player_gui.h"
#include "resources.h"
#include <iostream>

class Player : public Entity
{
  public:
  explicit Player(Resources &r);
  void render(sf::RenderTarget &target) override;
  sf::Sprite &get_sprite();

  private:
  Resources &resources;
  PlayerGUI gui;
  std::string name{};
  int level{};
  double hp{};
  double max_hp{};
  double xp{};
  double required_xp{};
  sf::Sprite sprite{};
};

#endif //_PLAYER_H_
