#include "resource_manager.h"
#include "../lib/json.hpp"
#include <iostream>

using nlohmann::json;
using std::cerr;
using std::cout;
using std::endl;
using std::to_string;

void ResourceManager::initialise_window()
{
  load_static_rects();
  // Player
  load_player_sprite();
  player_sprite.setPosition(655.0f, 680.0f);
  player_sprite.setScale(0.6f, 0.6f);
  player_texture.setSmooth(true);
  // Player info
  load_default_font();
  player_info.setFont(default_font);
  player_info.setCharacterSize(17);
  player_info.setFillColor(sf::Color::White);
  player_info.setLetterSpacing(0.5f);
  sf::FloatRect player_info_bounds = player_info.getLocalBounds();
  player_info.setPosition(697.0f - player_info_bounds.width / 2, 832.0f);
  // Enemy
  enemy_sprite.setPosition(1040.0f, 650.0f);
  enemy_sprite.setScale(0.9f, 0.9f);
  enemy_texture.setSmooth(true);
  // Enemy info
  enemy_info.setFont(default_font);
  enemy_info.setCharacterSize(17);
  enemy_info.setFillColor(sf::Color::White);
  enemy_info.setLetterSpacing(0.5f);
  sf::FloatRect enemy_info_bounds = enemy_info.getLocalBounds();
  enemy_info.setPosition(1098.0f - enemy_info_bounds.width / 2, 832.0f);
  load_static_text();
}

void ResourceManager::load_player_sprite()
{
  if (!player_texture.loadFromFile(resources_path + "img/player.png"))
  {
    cerr << "Failed to load player sprite." << endl;
  }
  this->player_sprite.setTexture(player_texture);
}

void ResourceManager::set_enemy(Stage stage, Enemy enemy)
{
  string enemy_name = enemy.name;
  replace(enemy_name.begin(), enemy_name.end(), ' ', '_');
  std::transform(enemy_name.begin(), enemy_name.end(), enemy_name.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  string img_path = resources_path + "img/enemies/stage_" +
                    to_string(to_stage_number(stage.name)) + "/" + enemy_name +
                    ".png";
  if (!enemy_texture.loadFromFile(img_path))
  {
    cerr << "Failed to load enemy sprite." << endl;
  }
  this->enemy_sprite.setTexture(enemy_texture);
  enemy_info.setString("Lv. " + to_string(enemy.level) + " " + enemy.name);
  enemy_hp_bar.set_max_value(enemy.max_hp);
  enemy_hp_bar.set_value(enemy.hp);
}

void ResourceManager::set_player(Player player)
{
  player_info.setString("Lv. " + to_string(player.level) + " " + player.name);
  player_hp_bar.set_max_value(player.max_hp);
  player_hp_bar.set_value(player.hp);
  player_xp_bar.set_max_value(player.required_xp);
  player_xp_bar.set_value(player.xp);
}

void ResourceManager::set_background(StageName game_stage)
{
  string stage_number = std::to_string(to_stage_number(game_stage));
  string path = resources_path + "/img/background/" + (stage_number) + ".jpg";
  if (!background_texture.loadFromFile(path))
  {
    cerr << "Failed to load background." << endl;
  }
  background_sprite.setTexture(background_texture);
}

void ResourceManager::load_static_rects()
{
  battle_area_rect.set_size(sf::Vector2f(746.0f, 464.0f));
  battle_area_rect.set_corners_radius(25);
  battle_area_rect.set_corner_point_count(50);
  battle_area_rect.setFillColor(sf::Color(0, 0, 0, 230));
  battle_area_rect.setPosition(585.0f, 500.0f);

  player_info_rect.set_size(sf::Vector2f(192, 25));
  player_info_rect.set_corners_radius(12);
  player_info_rect.set_corner_point_count(20);
  player_info_rect.setFillColor(sf::Color(0, 0, 0, 230));
  player_info_rect.setPosition(603.0f, 831.0f);

  enemy_info_rect.set_size(sf::Vector2f(435, 25));
  enemy_info_rect.set_corners_radius(12);
  enemy_info_rect.set_corner_point_count(20);
  enemy_info_rect.setFillColor(sf::Color(0, 0, 0, 230));
  enemy_info_rect.setPosition(880.0f, 831.0f);
}

void ResourceManager::load_default_font()
{
  if (!default_font.loadFromFile(resources_path + "font/Righteous-Regular.ttf"))
  {
    cerr << "Failed to load font." << endl;
  }
}

void ResourceManager::load_static_text()
{
  player_hp_text.setFont(default_font);
  player_hp_text.setCharacterSize(13);
  player_hp_text.setFillColor(sf::Color::White);
  player_hp_text.setLetterSpacing(0.5f);
  player_hp_text.setPosition(603.0f, 868.0f);
  player_hp_text.setString("HP");

  player_fever_text.setFont(default_font);
  player_fever_text.setCharacterSize(13);
  player_fever_text.setFillColor(sf::Color::White);
  player_fever_text.setLetterSpacing(0.5f);
  player_fever_text.setPosition(603.0f, 893.0f);
  player_fever_text.setString("FV");

  player_xp_text.setFont(default_font);
  player_xp_text.setCharacterSize(13);
  player_xp_text.setFillColor(sf::Color::White);
  player_xp_text.setLetterSpacing(0.5f);
  player_xp_text.setPosition(603.0f, 918.0f);
  player_xp_text.setString("XP");

  enemy_hp_text.setFont(default_font);
  enemy_hp_text.setCharacterSize(13);
  enemy_hp_text.setFillColor(sf::Color::White);
  enemy_hp_text.setLetterSpacing(0.5f);
  enemy_hp_text.setPosition(882.0f, 868.0f);
  enemy_hp_text.setString("HP");
}

int ResourceManager::to_stage_number(StageName game_stage)
{
  switch (game_stage)
  {
  case StageName::GREEN_FOREST:
    return 1;
  case StageName::DARK_FOREST:
    return 2;
  case StageName::MAGIC_FOREST:
    return 3;
  case StageName::CITY_ENTRANCE:
    return 4;
  case StageName::FORGOTTEN_ROAD:
    return 5;
  case StageName::HAUNTED_MARKETPLACE:
    return 6;
  case StageName::GOLDEN_TEMPLE:
    return 7;
  case StageName::INFERNO:
    return 8;
  }
}

std::vector<sf::Drawable *> ResourceManager::get_drawables()
{
  std::vector<sf::Drawable *> drawables{};
  drawables.push_back(&background_sprite);
  drawables.push_back(&battle_area_rect);
  drawables.push_back(&player_info_rect);
  drawables.push_back(&enemy_info_rect);
  drawables.push_back(&player_sprite);
  drawables.push_back(&enemy_sprite);
  drawables.push_back(&player_info);
  drawables.push_back(&enemy_info);
  drawables.push_back(&enemy_hp_bar);
  drawables.push_back(&enemy_hp_text);
  drawables.push_back(&player_hp_text);
  drawables.push_back(&player_hp_bar);
  drawables.push_back(&player_fever_text);
  drawables.push_back(&player_fever_bar);
  drawables.push_back(&player_xp_text);
  drawables.push_back(&player_xp_bar);
  return drawables;
}

const Sprite &ResourceManager::get_player_sprite() const
{
  return player_sprite;
}
const Sprite &ResourceManager::get_enemy_sprite() const { return enemy_sprite; }