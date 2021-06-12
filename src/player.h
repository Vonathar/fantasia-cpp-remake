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
