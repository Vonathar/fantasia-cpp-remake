#ifndef _ENEMY_GUI_H_
#define _ENEMY_GUI_H_

#include "../../interfaces/clickable.h"
#include "../resources.h"
#include "SFML/Graphics.hpp"
#include "reusable/progress_bar.h"
#include <iostream>

class EnemyGUI : public sf::Drawable, public Clickable
{
  public:
  explicit EnemyGUI(Resources &r);
  bool boundaries_contain(sf::Vector2f &pos) override;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void set_info(const std::string &name, int level);
  void set_hp(double hp);
  void set_max_hp(double max_hp);
  void set_texture(const sf::Texture &texture);
  sf::Sprite &get_sprite();

  private:
  Resources &resources;
  ProgressBar hp_bar{407, sf::Color(207, 63, 46), 907.0f, 871.0f};
  sf::Sprite sprite{};
  sf::Text info;
};

#endif // _ENEMY_GUI_H_
