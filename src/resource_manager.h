#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include "SFML/Graphics.hpp"
#include "enum/game_stage.h"
#include <iostream>

using sf::Font;
using sf::Sprite;
using sf::Texture;
using std::string;

/**
 * A class responsible for loading and accessing graphical resources.
 */
class ResourceManager {

 public:
  /**
   * Loads all the required initial resources and sets their initial position.
   */
  void initialise_window ();
  Sprite get_player_sprite ();
  Sprite get_background_sprite ();
  Font get_default_font ();

 private:
  /**
   * Loads the default player sprite from a resource file.
   */
  void load_player_sprite ();
  /**
   * Loads the background sprite of a given game stage from a resource file.
   *
   * @param game_stage the game stage.
   */
  void load_background_sprite (GameStage game_stage);
  /**
   * Loads the default font from a resource file.
   */
  void load_default_font ();
  /**
   * Returns the numerical representation of a game stage.
   *
   * @param game_stage the game stage.
   * @return the numerical representation of the game stage.
   */
  int to_stage_number (GameStage game_stage);
  Sprite player_sprite{};
  Sprite background_sprite{};
  Texture player_texture;
  Texture background_texture;
  Font default_font;
  string resources_path{"../res/"};
};

#endif//_RESOURCE_MANAGER_H_
