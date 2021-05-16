#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include "SFML/Graphics.hpp"
#include "clickable.h"
#include "entity/enemy.h"
#include "entity/player.h"
#include "entity/stage.h"
#include "enum/stage_name.h"
#include "gui/progress_bar.h"
#include "gui/rounded_rectangle_shape.h"
#include <iostream>
#include <vector>

using sf::Color;
using sf::Font;
using sf::ProgressBar;
using sf::RoundedRectangleShape;
using sf::Sprite;
using sf::Text;
using sf::Texture;
using std::string;

/**
 * A class responsible for loading and accessing graphical resources.
 */
class ResourceManager
{
  public:
  void initialise_window();
  void set_enemy(Enemy enemy);
  void set_player(Player player);
  void set_background(StageName game_stage);
  std::vector<sf::Drawable *> get_drawables();
  const Sprite &get_player_sprite() const;
  const Sprite &get_enemy_sprite() const;

  private:
  /**
   * Returns the numerical representation of a game name.
   *
   * @param game_stage the game name.
   * @return the numerical representation of the game name.
   */
  int to_stage_number(StageName game_stage);
  void load_static_resources();
  void init_static_rects();
  void init_static_text();

  Sprite player_sprite{};
  Sprite enemy_sprite{};
  Sprite background_sprite{};
  RoundedRectangleShape battle_area_rect{};
  RoundedRectangleShape player_info_rect{};
  RoundedRectangleShape enemy_info_rect{};
  ProgressBar enemy_hp_bar{407, Color(207, 63, 46), 907.0f, 871.0f};
  ProgressBar player_hp_bar{169, Color(207, 63, 46), 625.0f, 871.0f};
  ProgressBar player_fever_bar{689, Color(141, 102, 241), 625.0f, 896.0f};
  ProgressBar player_xp_bar{689, Color(166, 255, 17), 625.0f, 921.0f};
  Texture player_texture;
  Texture enemy_texture;
  Texture background_texture;
  Font default_font;
  Text player_info;
  Text enemy_info;
  Text player_hp_text;
  Text player_fever_text;
  Text player_xp_text;
  Text enemy_hp_text;
  string resources_path{"./res/"};
};

#endif //_RESOURCE_MANAGER_H_
