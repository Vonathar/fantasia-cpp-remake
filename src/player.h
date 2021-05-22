#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "SFML/Graphics.hpp"
#include "entity.h"
#include "player_gui.h"
#include "player_rank.h"
#include "resources.h"
#include <iostream>

class Player : public Entity
{
  public:
  explicit Player(Resources &r);
  void render(sf::RenderTarget &target) override;
  void increment_level();
  sf::Sprite &get_sprite();
  void set_hp(const double &n);
  void set_max_hp(const double &n);
  void set_xp(const double &n);
  void set_required_xp(const double &n);
  void set_fever(const double &n);

  private:
  Resources &resources;
  sf::Sprite sprite{};
  PlayerRank rank{};
  PlayerGUI gui;
  int level{};
  double hp{};
  double max_hp{};
  double xp{};
  double required_xp{};
  double fever{};

  const double base_max_hp = 500;
  const double base_required_xp = 250;
};

#endif //_PLAYER_H_
