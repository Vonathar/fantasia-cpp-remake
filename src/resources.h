#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include "enemy_name.h"
#include "stage_name.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

class Resources
{
  public:
  Resources();
  sf::Font &get_default_font();
  sf::Texture &get_background_texture(StageName stage_name);
  sf::Texture &get_enemy_texture(EnemyName enemy_name);
  sf::Texture &get_player_texture();

  private:
  std::string resources_path{"../res/"};
  sf::Font default_font{};
  sf::Texture player_texture{};
  std::map<StageName, std::unique_ptr<sf::Texture>> background_textures{};
  std::map<EnemyName, std::unique_ptr<sf::Texture>> enemy_textures{};
  void load_background(StageName stage_name, std::string file_name);
  void load_enemy(EnemyName enemy_name, std::string file_name);
  void load_static_resources();
};

#endif //_RESOURCES_H_
