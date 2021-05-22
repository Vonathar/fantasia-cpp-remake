#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "SFML/Graphics.hpp"
#include "enemy_generator.h"
#include "enemy_gui.h"
#include "enemy_name.h"
#include "entity.h"
#include "resources.h"
#include <iostream>

struct Enemy : public Entity
{
  public:
  explicit Enemy(Resources &r);
  void render(sf::RenderTarget &target) override;
  void receive_damage(const double &damage_received);
  void regenerate(const StageName &stage_name, const int &min_level);
  void set_hp(const double &n);
  void set_max_hp(const double &n);
  void set_info(const std::string &n, const int &lv);
  void set_texture(const sf::Texture &texture);
  sf::Sprite &get_sprite();

  private:
  Resources &resources;
  EnemyGenerator generator{};
  EnemyGUI gui;
  std::string name{};
  int level{};
  double hp{};
  double max_hp{};
  double damage{};
  sf::Sprite sprite{};

  const double base_max_hp = 500;
  const double base_damage = 3;
};

#endif //_ENEMY_H_
