#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../enums/player_rank.h"
#include "../gui/drawables/player_gui.h"
#include "../gui/resources.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class Player : public sf::Drawable
{
  public:
  explicit Player(Resources &r);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void receive_damage(const double &damage_received);
  void receive_xp(const double &n);
  void regenerate();
  void increment_level();
  void set_hp(const double &n);
  void set_max_hp(const double &n);
  void set_xp(const double &n);
  void set_required_xp(const double &n);
  void set_fever(const double &n);
  void set_regenerating(bool r);
  double get_click_damage() const;
  double &get_max_hp();
  sf::Sprite &get_sprite();
  bool &is_dead();
  bool &is_regenerating();

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
  double click_damage{};
  bool dead{};
  bool regenerating{};

  const double base_max_hp = 500;
  const double base_required_xp = 250;
  const double base_click_damage = 50;
};

#endif //_PLAYER_H_
