#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include "enemy_name.h"
#include "resource_name.h"
#include "stage_name.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

class Resources
{
  public:
  Resources();
  sf::Font &get_font(ResourceName resource_name);
  sf::Texture &get_texture(StageName stage_name);
  sf::Texture &get_texture(EnemyName enemy_name);
  sf::Texture &get_texture(ResourceName resource_name);

  private:
  std::string resources_path{"../res/"};
  std::map<StageName, std::unique_ptr<sf::Texture>> background_textures{};
  std::map<EnemyName, std::unique_ptr<sf::Texture>> enemy_textures{};
  std::map<ResourceName, std::unique_ptr<sf::Texture>> other_textures{};
  std::map<ResourceName, std::unique_ptr<sf::Font>> fonts{};
  void load_texture(StageName stage_name, const std::string &file_name);
  void load_texture(EnemyName enemy_name, const std::string &file_name);
  void load_texture(ResourceName resource_name, const std::string &file_name);
  void load_font(ResourceName resource_name, const std::string &file_name);
};

#endif //_RESOURCES_H_
