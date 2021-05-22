#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "SFML/Graphics.hpp"
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
  void set_hp(const float &n);
  void set_max_hp(const float &n);
  void set_info(const std::string &n, const int &lv);
  sf::Sprite &get_sprite();

  private:
  Resources &resources;
  EnemyGUI gui;
  std::string name{};
  int level{};
  float hp{};
  float max_hp{};
  sf::Sprite sprite{};
};

#endif //_ENEMY_H_
