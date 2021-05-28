#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "SFML/Graphics.hpp"
#include "enemy_generator.h"
#include "enemy_gui.h"
#include "enemy_name.h"
#include "entity.h"
#include "resources.h"
#include <iostream>

class Enemy : public Entity
{
  public:
  explicit Enemy(Resources &r);
  void render(sf::RenderTarget &target) override;
  void receive_damage(const double &damage_received);
  void regenerate(const StageName &stage_name, const int &min_level,
                  const bool &is_boss);
  void set_hp(const double &n);
  void set_max_hp(const double &n);
  void set_info(const std::string &n, const int &lv);
  void set_texture(const sf::Texture &texture);
  void set_regenerating(bool r);
  sf::Sprite &get_sprite();
  double &get_xp_held();
  double &get_damage();
  bool &is_dead();
  bool &is_regenerating();

  private:
  Resources &resources;
  EnemyGenerator generator{};
  EnemyGUI gui;
  int level{};
  double hp{};
  double max_hp{};
  double damage{};
  double xp_held{};
  sf::Sprite sprite{};
  bool dead{};
  bool regenerating{};

  const double base_max_hp = 500;
  const double base_damage = 100;
  const double base_xp_held = 25;
};

#endif //_ENEMY_H_
