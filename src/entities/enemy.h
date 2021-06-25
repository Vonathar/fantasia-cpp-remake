#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "../enemy_generator.h"
#include "../enums/enemy_name.h"
#include "../gui/drawables/enemy_gui.h"
#include "../gui/resources.h"
#include "../interfaces/clickable.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class Enemy : public sf::Drawable
{
  public:
  explicit Enemy(Resources &r);
  bool is_sprite_in_bounds(sf::Vector2f &pos);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void receive_damage(const double &damage_received);
  void regenerate(const StageName &stage_name, const int &min_level,
                  const bool &is_boss);
  void set_hp(const double &n);
  void set_max_hp(const double &n);
  void set_info(const std::string &n, const int &lv);
  void set_regenerating(bool r);
  sf::Sprite &get_sprite();
  double &get_xp_held();
  double &get_coins_held();
  double &get_damage();
  bool &is_dead();
  bool &is_regenerating();
  bool &is_boss();

  private:
  Resources &resources;
  EnemyGenerator generator{};
  EnemyGUI gui;
  int level{};
  double hp{};
  double max_hp{};
  double damage{};
  double xp_held{};
  double coins_held{};
  bool dead{};
  bool regenerating{};
  bool boss{};

  const double base_max_hp = 500;
  const double base_damage = 100;
  const double base_xp_held = 25;
  const double base_coins_held = 25;
};

#endif //_ENEMY_H_
