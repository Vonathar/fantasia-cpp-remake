#ifndef _ENEMY_GUI_H_
#define _ENEMY_GUI_H_

#include "SFML/Graphics.hpp"
#include "entity.h"
#include "progress_bar.h"
#include "resources.h"
#include <iostream>

class EnemyGUI : public Entity
{
  public:
  explicit EnemyGUI(Resources &r);
  void render(sf::RenderTarget &target) override;
  void set_info(std::string name, int level);
  void set_hp(double hp);
  void set_max_hp(double max_hp);

  private:
  Resources &resources;
  ProgressBar hp_bar{407, sf::Color(207, 63, 46), 907.0f, 871.0f};
  sf::Text info;
};

#endif // _ENEMY_GUI_H_
