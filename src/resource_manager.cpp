#include "resource_manager.h"
#include "../lib/json.hpp"
#include <iostream>

using nlohmann::json;
using std::cerr;
using std::cout;
using std::endl;
using std::to_string;

void ResourceManager::initialise_window ()
{
  // Background
  load_background_sprite (GameStage::CITY_ENTRANCE);
  // Battle area
  load_battle_area_sprite ();
  battle_area_sprite.setPosition (425.0f, 350.0f);
  battle_area_sprite.setColor (sf::Color (225, 225, 225, 230));
  // Player
  load_player_sprite ();
  player_sprite.setPosition (475.0f, 540.0f);
  player_sprite.setScale (0.65f, 0.65f);
  player_texture.setSmooth (true);
  // Player info
  load_default_font ();
  player_info.setFont (default_font);
  player_info.setPosition (475.0f, 700.0f);
  player_info.setCharacterSize (17);
  player_info.setFillColor (sf::Color::White);
  player_info.setLetterSpacing (0.5f);
  set_player_info (1, "Mercenary");
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

void ResourceManager::load_battle_area_sprite ()
{
  if (!battle_area_texture.loadFromFile (resources_path
										 + R"(/img/battle_area.png)"))
  {
	cerr << "Failed to load battle area." << endl;
  }
  battle_area_sprite.setTexture (battle_area_texture);
}

void ResourceManager::load_default_font ()
{
  if (!default_font.loadFromFile (resources_path
								  + R"(font/Righteous-Regular.ttf)"))
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

sf::Sprite ResourceManager::get_battle_area_sprite ()
{
  return battle_area_sprite;
}

Text ResourceManager::get_player_info ()
{
  return player_info;
}

void ResourceManager::set_player_info (int player_level, string player_name)
{
  player_info.setString ("Lv. " + to_string (player_level) + " " + player_name);
}
