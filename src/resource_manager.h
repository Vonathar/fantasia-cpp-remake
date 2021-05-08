#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include "SFML/Graphics.hpp"
#include "enum/game_stage.h"
#include "gui/rounded_rectangle_shape.h"
#include "struct/enemy.h"
#include <iostream>
#include <vector>

using sf::Font;
using sf::Sprite;
using sf::Text;
using sf::Texture;
using std::string;

/**
 * A class responsible for loading and accessing graphical resources.
 */
class ResourceManager {

 public:
  /**
   * Loads all resources and sets their initial position.
   */
  void initialise_window ();
  std::vector<sf::Drawable *> get_drawables ();

 private:
  /**
   * Loads the default player sprite from a resource file.
   */
  void load_player_sprite ();
  /**
   * Loads the given enemy sprite from a resource file.
   */
  void load_enemy_sprite (GameStage game_stage, const Enemy &enemy);
  /**
   * Loads the background sprite of a given game stage from a resource file.
   *
   * @param game_stage the game stage.
   */
  void load_background_sprite (GameStage game_stage);
  /**
   * Loads the battle area sprite from a resource file.
   */
  void load_battle_area_rect ();
  /**
   * Loads the player info background sprite from a resource file.
   */
  void load_player_info_rect ();
  /**
   * Loads the enemy info background sprite from a resource file.
   */
  void load_enemy_info_rect ();
  /**
   * Loads the default font from a resource file.
   */
  void load_default_font ();
  /**
   * Updates the player name and level.
   *
   * @param player_level the new level of the player.
   * @param player_name the new name of the player.
   */
  void set_player_info (int player_level, string player_name);
  /**
   * Updates the enemy name and level.
   *
   * @param enemy_level the new level of the enemy.
   * @param enemy_name the new name of the enemy.
   */
  void set_enemy_info (int enemy_level, string enemy_name);
  /**
   * Returns the numerical representation of a game stage.
   *
   * @param game_stage the game stage.
   * @return the numerical representation of the game stage.
   */
  int to_stage_number (GameStage game_stage);
  Sprite player_sprite{};
  Sprite enemy_sprite{};
  Sprite background_sprite{};
  sf::RoundedRectangleShape battle_area_rect{};
  sf::RoundedRectangleShape player_info_rect{};
  sf::RoundedRectangleShape enemy_info_rect{};
  Texture player_texture;
  Texture enemy_texture;
  Texture background_texture;
  Texture battle_area_texture{};
  Font default_font;
  Text player_info;
  Text enemy_info;
  string resources_path{"../res/"};
};

#endif//_RESOURCE_MANAGER_H_
