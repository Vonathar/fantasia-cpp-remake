#ifndef _STAGE_H_
#define _STAGE_H_

#include "../enums/stage_name.h"
#include "../gui/drawables/stage/stage_gui.h"
#include "../gui/resources.h"
#include "../interfaces/clickable.h"
#include "SFML/Graphics.hpp"

class Stage : public sf::Drawable
{

  public:
  explicit Stage(Resources &r, StageGUI &g);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  bool is_next_level_in_bounds(sf::Vector2f &pos);
  bool is_boss_button_in_bounds(sf::Vector2f &pos);
  void record_enemy_death(bool is_boss);
  void set_boss_fight(bool boss_fight);
  void increment_level();
  const StageName &get_name();
  const int &get_level() const;
  bool is_next_level_unlocked() const;
  const bool &is_boss_available() const;

  private:
  Resources &resources;
  sf::Sprite sprite{};
  StageGUI gui;
  StageName name;
  int level;
  bool boss_available;
  int enemies_left;
  void increment_stage();

  const int ENEMIES_PER_STAGE = 5;
};

#endif //_STAGE_H_
