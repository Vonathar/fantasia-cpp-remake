#include "resource_manager.h"
#include "../lib/json.hpp"
#include <iostream>

using nlohmann::json;
using std::cerr;
using std::cout;
using std::endl;

void ResourceManager::initialise_window ()
{
  load_background_sprite (GameStage::CITY_ENTRANCE);
  background_sprite.setPosition (0.0f, 0.0f);
  background_sprite.setScale (0.6f, 0.6f);
  load_player_sprite ();
  player_sprite.setPosition (700.0f, 600.0f);
  player_sprite.setScale (0.7f, 0.7f);
}

void ResourceManager::load_player_sprite ()
{
  if (!player_texture.loadFromFile (resources_path + R"(/img/player.png)"))
  {
	cerr << "Failed to load player sprite." << endl;
  }
  this->player_sprite.setTexture (player_texture);
}

void ResourceManager::load_background_sprite (GameStage game_stage)
{
  string stage_number = std::to_string (to_stage_number (game_stage));
  string path =
	  resources_path + R"(/img/background/)" + (stage_number) + ".jpg";
  if (!background_texture.loadFromFile (path))
  {
	cerr << "Failed to load background." << endl;
  }
  background_sprite.setTexture (background_texture);
}

void ResourceManager::load_default_font ()
{
  if (!default_font.loadFromFile (resources_path
								  + R"(/font/Righteous-Regular.ttf)"))
  {
	cerr << "Failed to load font." << endl;
  }
}

int ResourceManager::to_stage_number (GameStage game_stage)
{
  switch (game_stage)
  {
  case GameStage::CITY_ENTRANCE: return 1;
  case GameStage::DARK_FOREST: return 2;
  case GameStage::FORGOTTEN_ROAD: return 3;
  case GameStage::GOLDEN_TEMPLE: return 4;
  case GameStage::GREEN_FOREST: return 5;
  case GameStage::HAUNTED_MARKETPLACE: return 6;
  case GameStage::INFERNO: return 7;
  case GameStage::MAGIC_FOREST: return 8;
  }
}

sf::Sprite ResourceManager::get_player_sprite ()
{
  return player_sprite;
}

sf::Sprite ResourceManager::get_background_sprite ()
{
  return background_sprite;
}

sf::Font ResourceManager::get_default_font ()
{
  return default_font;
}
