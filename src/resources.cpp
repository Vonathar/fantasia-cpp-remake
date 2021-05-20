#include "resources.h"
#include <iostream>

Resources::Resources()
{
  load_static_resources();

  load_background(StageName::GREEN_FOREST, "green_forest.jpg");
  load_background(StageName::DARK_FOREST, "dark_forest.jpg");
  load_background(StageName::MAGIC_FOREST, "magic_forest.jpg");
  load_background(StageName::CITY_ENTRANCE, "city_entrance.jpg");
  load_background(StageName::FORGOTTEN_ROAD, "forgotten_road.jpg");
  load_background(StageName::HAUNTED_MARKETPLACE, "haunted_marketplace.jpg");
  load_background(StageName::GOLDEN_TEMPLE, "golden_temple.jpg");
  load_background(StageName::INFERNO, "inferno.jpg");

  load_enemy(EnemyName::FAIRY_FILIA, "stage_1/fairy_filia.png");
  load_enemy(EnemyName::GRASSHOPPER, "stage_1/grasshopper.png");
  load_enemy(EnemyName::GREEN_SPIDER, "stage_1/green_spider.png");
  load_enemy(EnemyName::IMPERIAL_WIDOW, "stage_1/imperial_widow.png");
  load_enemy(EnemyName::MOTHY, "stage_1/mothy.png");
  load_enemy(EnemyName::SHROOMY, "stage_1/shroomy.png");
  load_enemy(EnemyName::SPORA, "stage_1/spora.png");
  load_enemy(EnemyName::RUKKHA, "stage_1/rukkha.png");
  load_enemy(EnemyName::DAIDARABOTCHI, "stage_1/daidarabotchi.png");
  load_enemy(EnemyName::TELLIA, "stage_1/tellia.png");

  load_enemy(EnemyName::DARK_ANGEL, "stage_2/dark_angel.png");
  load_enemy(EnemyName::REAPER, "stage_2/reaper.png");
  load_enemy(EnemyName::BANSHEE, "stage_2/banshee.png");
  load_enemy(EnemyName::IMP, "stage_2/imp.png");
  load_enemy(EnemyName::GHAUL, "stage_2/ghaul.png");
  load_enemy(EnemyName::SEEKER, "stage_2/seeker.png");
  load_enemy(EnemyName::SUCCUBUS, "stage_2/succubus.png");
  load_enemy(EnemyName::OGRE, "stage_2/ogre.png");
  load_enemy(EnemyName::BLOOD_FERAL, "stage_2/blood_feral.png");
  load_enemy(EnemyName::DARK_QUEEN_YOA, "stage_2/dark_queen_yoa.png");
  load_enemy(EnemyName::KNIGHT_REMMENT, "stage_2/knight_remment.png");
}

sf::Texture &Resources::get_background_texture(StageName stage_name)
{
  auto pair = background_textures.find(stage_name);
  return *pair->second;
}

sf::Texture &Resources::get_player_texture()
{
  return player_texture;
}

sf::Font &Resources::get_default_font()
{
  return default_font;
}

sf::Texture &Resources::get_enemy_texture(EnemyName enemy_name)
{
  auto pair = enemy_textures.find(enemy_name);
  return *pair->second;
}

void Resources::load_background(StageName stage_name, std::string file_name)
{
  std::unique_ptr<sf::Texture> texture(new sf::Texture());
  std::string path = resources_path + "img/background/" + file_name;
  texture->loadFromFile(path);
  background_textures.insert(std::make_pair(stage_name, std::move(texture)));
}

void Resources::load_enemy(EnemyName enemy_name, std::string file_name)
{
  std::unique_ptr<sf::Texture> texture(new sf::Texture());
  std::string path = resources_path + "img/enemies/" + file_name;
  texture->loadFromFile(path);
  texture->setSmooth(true);
  enemy_textures.insert(std::make_pair(enemy_name, std::move(texture)));
}

void Resources::load_static_resources()
{
  if (!default_font.loadFromFile(resources_path + "font/Righteous-Regular.ttf"))
  {
    std::cerr << "Failed to load font." << std::endl;
  }
  if (!player_texture.loadFromFile(resources_path + "img/player.png"))
  {
    std::cerr << "Failed to load player sprite." << std::endl;
  }
  player_texture.setSmooth(true);
}