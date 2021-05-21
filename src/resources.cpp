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

  load_enemy(EnemyName::EARTH_BULL, "stage_3/earth_bull.png");
  load_enemy(EnemyName::BUSH_WISP, "stage_3/bush_wisp.png");
  load_enemy(EnemyName::LEAF_IMP, "stage_3/leaf_imp.png");
  load_enemy(EnemyName::EARTH_LION, "stage_3/earth_lion.png");
  load_enemy(EnemyName::MANDRAKE, "stage_3/mandrake.png");
  load_enemy(EnemyName::ROCK_GOLEM, "stage_3/rock_golem.png");
  load_enemy(EnemyName::EARTH_SNAKE, "stage_3/earth_snake.png");
  load_enemy(EnemyName::EARTH_SPAWN, "stage_3/earth_spawn.png");
  load_enemy(EnemyName::EARTH_TURTLE, "stage_3/earth_turtle.png");
  load_enemy(EnemyName::EARTH_WISP, "stage_3/earth_wisp.png");
  load_enemy(EnemyName::QUEEN_RAFFLESIA, "stage_3/queen_rafflesia.png");
  load_enemy(EnemyName::QUEEN_YGGDRASIL, "stage_3/queen_yggdrasil.png");
  load_enemy(EnemyName::GEMSTONE_GOLEM, "stage_3/gemstone_golem.png");

  load_enemy(EnemyName::GOBLIN_ARCHER, "stage_4/goblin_archer.png");
  load_enemy(EnemyName::GOBLIN_ELITE, "stage_4/goblin_elite.png");
  load_enemy(EnemyName::GOBLIN_GRUNT, "stage_4/goblin_grunt.png");
  load_enemy(EnemyName::GOBLIN_MAGE, "stage_4/goblin_mage.png");
  load_enemy(EnemyName::GOBLIN_RAIDER, "stage_4/goblin_raider.png");
  load_enemy(EnemyName::ROGUE_SWORDMAN, "stage_4/rogue_swordman.png");
  load_enemy(EnemyName::ROGUE_MONK, "stage_4/rogue_monk.png");
  load_enemy(EnemyName::ROGUE_ASSASSIN, "stage_4/rogue_assassin.png");
  load_enemy(EnemyName::BONEMASK, "stage_4/bonemask.png");
  load_enemy(EnemyName::THE_FALLEN, "stage_4/the_fallen.png");
  load_enemy(EnemyName::ANCIENT_AUTOMATON, "stage_4/ancient_automaton.png");

  load_enemy(EnemyName::ELF_ARCHER, "stage_5/elf_archer.png");
  load_enemy(EnemyName::ELF_ASSASSIN, "stage_5/elf_assassin.png");
  load_enemy(EnemyName::CROSSBOW_ELF, "stage_5/crossbow_elf.png");
  load_enemy(EnemyName::DUAL_SWORD_ELF, "stage_5/dual_sword_elf.png");
  load_enemy(EnemyName::ELF_MAGE, "stage_5/elf_mage.png");
  load_enemy(EnemyName::SPEAR_ELF, "stage_5/spear_elf.png");
  load_enemy(EnemyName::SWORD_ELF, "stage_5/sword_elf.png");
  load_enemy(EnemyName::NATURE_LINKER, "stage_5/nature_linker.png");
  load_enemy(EnemyName::ROGUE_ELF, "stage_5/rogue_elf.png");
  load_enemy(EnemyName::SPELLCASTER, "stage_5/spellcaster.png");
  load_enemy(EnemyName::CELESTIAL_BEATRIX, "stage_5/celestial_beatrix.png");
  load_enemy(EnemyName::ALFADRIEL, "stage_5/alfadriel.png");
  load_enemy(EnemyName::SON_OF_VALHALLA, "stage_5/son_of_valhalla.png");

  load_enemy(EnemyName::GAZERS_EYEWING, "stage_6/gazers_eyewing.png");
  load_enemy(EnemyName::GAZERS_SKULL, "stage_6/gazers_skull.png");
  load_enemy(EnemyName::TENTEYE, "stage_6/tenteye.png");
  load_enemy(EnemyName::GHOSTUS, "stage_6/ghostus.png");
  load_enemy(EnemyName::KNIGHT_DESTRAND, "stage_6/knight_destrand.png");
  load_enemy(EnemyName::KNIGHT_GALPHA, "stage_6/knight_galpha.png");
  load_enemy(EnemyName::KNIGHT_GOLIATH, "stage_6/knight_goliath.png");
  load_enemy(EnemyName::GHOST_PUPPET_PAILO, "stage_6/ghost_puppet_pailo.png");
  load_enemy(EnemyName::GHOST_REVELATOR, "stage_6/ghost_revelator.png");
  load_enemy(EnemyName::ASTRAL_LICH, "stage_6/astral_lich.png");
  load_enemy(EnemyName::ELDRITCH_GOD, "stage_6/eldritch_god.png");
  load_enemy(EnemyName::REAPER_NIHILO, "stage_6/reaper_nihilo.png");

  load_enemy(EnemyName::AXE_KNIGHT, "stage_7/axe_knight.png");
  load_enemy(EnemyName::GOLDEN_AXE_KNIGHT, "stage_7/golden_axe_knight.png");
  load_enemy(EnemyName::GUNNER_KNIGHT, "stage_7/gunner_knight.png");
  load_enemy(EnemyName::GOLDEN_GUNNER_KNIGHT,
             "stage_7/golden_gunner_knight.png");
  load_enemy(EnemyName::SPEAR_KNIGHT, "stage_7/spear_knight.png");
  load_enemy(EnemyName::GOLDEN_SPEAR_KNIGHT, "stage_7/golden_spear_knight.png");
  load_enemy(EnemyName::SWORD_KNIGHT, "stage_7/sword_knight.png");
  load_enemy(EnemyName::GOLDEN_SWORD_KNIGHT, "stage_7/golden_sword_knight.png");
  load_enemy(EnemyName::GOLDEN_HUANGLONG, "stage_7/golden_huanglong.png");
  load_enemy(EnemyName::GOLDEN_LADON, "stage_7/golden_ladon.png");
  load_enemy(EnemyName::GOLDEN_EMPEROR, "stage_7/golden_emperor.png");

  load_enemy(EnemyName::FIRE_BULL, "stage_8/fire_bull.png");
  load_enemy(EnemyName::FIRE_DRAGONSPAWN, "stage_8/fire_dragonspawn.png");
  load_enemy(EnemyName::FIRE_LION, "stage_8/fire_lion.png");
  load_enemy(EnemyName::FIRE_OGRE, "stage_8/fire_ogre.png");
  load_enemy(EnemyName::FIRE_SABRETOOTH, "stage_8/fire_sabretooth.png");
  load_enemy(EnemyName::FIRE_SALAMANDER, "stage_8/fire_salamander.png");
  load_enemy(EnemyName::FIRE_TURTLE, "stage_8/fire_turtle.png");
  load_enemy(EnemyName::VOLCANIC_MAIDEN, "stage_8/volcanic_maiden.png");
  load_enemy(EnemyName::FIRE_VULTURE, "stage_8/fire_vulture.png");
  load_enemy(EnemyName::FIRE_WISP, "stage_8/fire_wisp.png");
  load_enemy(EnemyName::NUCKELAVEE, "stage_8/nuckelavee.png");
  load_enemy(EnemyName::ILNOCT, "stage_8/ilnoct.png");
  load_enemy(EnemyName::HELLHOUND_GARM, "stage_8/hellhound_garm.png");
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

void Resources::load_background(StageName stage_name,
                                const std::string &file_name)
{
  std::unique_ptr<sf::Texture> texture(new sf::Texture());
  std::string path = resources_path + "img/background/" + file_name;
  texture->loadFromFile(path);
  background_textures.insert(std::make_pair(stage_name, std::move(texture)));
}

void Resources::load_enemy(EnemyName enemy_name, const std::string &file_name)
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