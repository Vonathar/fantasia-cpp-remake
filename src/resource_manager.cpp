#include "resource_manager.h"
#include "../lib/json.hpp"
#include "gui/rounded_rectangle_shape.h"
#include <iostream>

using nlohmann::json;
using std::cerr;
using std::cout;
using std::endl;
using std::to_string;

void ResourceManager::initialise_window ()
{
  // Background
  load_background_sprite (GameStage::GREEN_FOREST);
  // Rects
  load_battle_area_rect ();
  load_player_info_rect ();
  load_enemy_info_rect ();
  // Player
  load_player_sprite ();
  player_sprite.setPosition (655.0f, 680.0f);
  player_sprite.setScale (0.6f, 0.6f);
  player_texture.setSmooth (true);
  // Player info
  load_default_font ();
  set_player_info (1, "Rogue");
  player_info.setFont (default_font);
  player_info.setCharacterSize (17);
  player_info.setFillColor (sf::Color::White);
  player_info.setLetterSpacing (0.5f);
  sf::FloatRect player_info_bounds = player_info.getLocalBounds ();
  player_info.setPosition (697.0f - player_info_bounds.width / 2, 832.0f);
  // Enemy
  Enemy e{};
  e.name = "Fairy Filia";
  e.level = 0;
  load_enemy_sprite (GameStage::GREEN_FOREST, e);
  enemy_sprite.setPosition (1040.0f, 650.0f);
  enemy_sprite.setScale (0.9f, 0.9f);
  enemy_texture.setSmooth (true);
  // Enemy info
  set_enemy_info (1, "Fairy Filia");
  enemy_info.setFont (default_font);
  enemy_info.setCharacterSize (17);
  enemy_info.setFillColor (sf::Color::White);
  enemy_info.setLetterSpacing (0.5f);
  sf::FloatRect enemy_info_bounds = enemy_info.getLocalBounds ();
  enemy_info.setPosition (1098.0f - enemy_info_bounds.width / 2, 832.0f);
  load_static_text ();
}

void ResourceManager::load_player_sprite ()
{
  if (!player_texture.loadFromFile (resources_path + "/img/player.png"))
  {
	cerr << "Failed to load player sprite." << endl;
  }
  this->player_sprite.setTexture (player_texture);
}

void ResourceManager::load_enemy_sprite (GameStage game_stage,
										 const Enemy &enemy)
{
  string enemy_name = enemy.name;
  replace (enemy_name.begin (), enemy_name.end (), ' ', '_');
  std::transform (enemy_name.begin (), enemy_name.end (), enemy_name.begin (),
				  [] (unsigned char c) { return std::tolower (c); });
  string img_path = resources_path + "/img/enemies/stage_"
					+ to_string (to_stage_number (game_stage)) + "/"
					+ enemy_name + ".png";
  if (!enemy_texture.loadFromFile (img_path))
  {
	cerr << "Failed to load enemy sprite." << endl;
  }
  this->enemy_sprite.setTexture (enemy_texture);
}

void ResourceManager::load_background_sprite (GameStage game_stage)
{
  string stage_number = std::to_string (to_stage_number (game_stage));
  string path = resources_path + "/img/background/" + (stage_number) + ".jpg";
  if (!background_texture.loadFromFile (path))
  {
	cerr << "Failed to load background." << endl;
  }
  background_sprite.setTexture (background_texture);
}

void ResourceManager::load_battle_area_rect ()
{
  battle_area_rect.set_size (sf::Vector2f (746.0f, 464.0f));
  battle_area_rect.set_corners_radius (25);
  battle_area_rect.set_corner_point_count (50);
  battle_area_rect.setFillColor (sf::Color (0, 0, 0, 230));
  battle_area_rect.setPosition (585.0f, 500.0f);
}

void ResourceManager::load_player_info_rect ()
{
  player_info_rect.set_size (sf::Vector2f (192, 25));
  player_info_rect.set_corners_radius (12);
  player_info_rect.set_corner_point_count (20);
  player_info_rect.setFillColor (sf::Color (0, 0, 0, 230));
  player_info_rect.setPosition (603.0f, 831.0f);
}

void ResourceManager::load_enemy_info_rect ()
{
  enemy_info_rect.set_size (sf::Vector2f (435, 25));
  enemy_info_rect.set_corners_radius (12);
  enemy_info_rect.set_corner_point_count (20);
  enemy_info_rect.setFillColor (sf::Color (0, 0, 0, 230));
  enemy_info_rect.setPosition (880.0f, 831.0f);
}

void ResourceManager::load_default_font ()
{
  if (!default_font.loadFromFile (resources_path
								  + "font/Righteous-Regular.ttf"))
  {
	cerr << "Failed to load font." << endl;
  }
}

void ResourceManager::load_static_text ()
{
  player_hp_text.setFont (default_font);
  player_hp_text.setCharacterSize (13);
  player_hp_text.setFillColor (sf::Color::White);
  player_hp_text.setLetterSpacing (0.5f);
  player_hp_text.setPosition (603.0f, 868.0f);
  player_hp_text.setString ("HP");

  player_fever_text.setFont (default_font);
  player_fever_text.setCharacterSize (13);
  player_fever_text.setFillColor (sf::Color::White);
  player_fever_text.setLetterSpacing (0.5f);
  player_fever_text.setPosition (603.0f, 893.0f);
  player_fever_text.setString ("FV");

  player_xp_text.setFont (default_font);
  player_xp_text.setCharacterSize (13);
  player_xp_text.setFillColor (sf::Color::White);
  player_xp_text.setLetterSpacing (0.5f);
  player_xp_text.setPosition (603.0f, 918.0f);
  player_xp_text.setString ("XP");

  enemy_hp_text.setFont (default_font);
  enemy_hp_text.setCharacterSize (13);
  enemy_hp_text.setFillColor (sf::Color::White);
  enemy_hp_text.setLetterSpacing (0.5f);
  enemy_hp_text.setPosition (882.0f, 868.0f);
  enemy_hp_text.setString ("HP");
}

int ResourceManager::to_stage_number (GameStage game_stage)
{
  switch (game_stage)
  {
  case GameStage::GREEN_FOREST: return 1;
  case GameStage::DARK_FOREST: return 2;
  case GameStage::MAGIC_FOREST: return 3;
  case GameStage::CITY_ENTRANCE: return 4;
  case GameStage::FORGOTTEN_ROAD: return 5;
  case GameStage::HAUNTED_MARKETPLACE: return 6;
  case GameStage::GOLDEN_TEMPLE: return 7;
  case GameStage::INFERNO: return 8;
  }
}

void ResourceManager::set_player_info (int player_level, string player_name)
{
  player_info.setString ("Lv. " + to_string (player_level) + " " + player_name);
}

void ResourceManager::set_enemy_info (int enemy_level, string enemy_name)
{
  enemy_info.setString ("Lv. " + to_string (enemy_level) + " " + enemy_name);
}

std::vector<sf::Drawable *> ResourceManager::get_drawables ()
{
  std::vector<sf::Drawable *> drawables{};
  drawables.push_back (&background_sprite);
  drawables.push_back (&battle_area_rect);
  drawables.push_back (&player_info_rect);
  drawables.push_back (&enemy_info_rect);
  drawables.push_back (&player_sprite);
  drawables.push_back (&enemy_sprite);
  drawables.push_back (&player_info);
  drawables.push_back (&enemy_info);
  drawables.push_back (&enemy_hp_bar);
  drawables.push_back (&enemy_hp_text);
  drawables.push_back (&player_hp_text);
  drawables.push_back (&player_hp_bar);
  drawables.push_back (&player_fever_text);
  drawables.push_back (&player_fever_bar);
  drawables.push_back (&player_xp_text);
  drawables.push_back (&player_xp_bar);
  return drawables;
}
