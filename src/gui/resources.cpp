#include "resources.h"
#include <iostream>

Resources::Resources()
{
  load_font(ResourceName::SKRANJI_FONT, "skranji_regular.ttf");
  load_font(ResourceName::RIGHTEOUS_FONT, "odibee_sans_regular.ttf");
  load_font(ResourceName::GREAT_VIBES_FONT, "great_vibes.ttf");

  load_texture(StageName::GREEN_FOREST, "green_forest.jpg");
  load_texture(StageName::DARK_FOREST, "dark_forest.jpg");
  load_texture(StageName::MAGIC_FOREST, "magic_forest.jpg");
  load_texture(StageName::CITY_ENTRANCE, "city_entrance.jpg");
  load_texture(StageName::FORGOTTEN_ROAD, "forgotten_road.jpg");
  load_texture(StageName::HAUNTED_MARKETPLACE, "haunted_marketplace.jpg");
  load_texture(StageName::GOLDEN_TEMPLE, "golden_temple.jpg");
  load_texture(StageName::INFERNO, "inferno.jpg");

  // Stage 1
  load_texture(EnemyName::FAIRY_FILIA, "stage_1/fairy_filia.png");
  load_texture(EnemyName::GRASSHOPPER, "stage_1/grasshopper.png");
  load_texture(EnemyName::GREEN_SPIDER, "stage_1/green_spider.png");
  load_texture(EnemyName::IMPERIAL_WIDOW, "stage_1/imperial_widow.png");
  load_texture(EnemyName::MOTHY, "stage_1/mothy.png");
  load_texture(EnemyName::SHROOMY, "stage_1/shroomy.png");
  load_texture(EnemyName::SPORA, "stage_1/spora.png");
  load_texture(EnemyName::RUKKHA, "stage_1/rukkha.png");
  load_texture(EnemyName::DAIDARABOTCHI, "stage_1/daidarabotchi.png");
  load_texture(EnemyName::TELLIA, "stage_1/tellia.png");
  // Stage 2
  load_texture(EnemyName::DARK_ANGEL, "stage_2/dark_angel.png");
  load_texture(EnemyName::REAPER, "stage_2/reaper.png");
  load_texture(EnemyName::BANSHEE, "stage_2/banshee.png");
  load_texture(EnemyName::IMP, "stage_2/imp.png");
  load_texture(EnemyName::GHAUL, "stage_2/ghaul.png");
  load_texture(EnemyName::SEEKER, "stage_2/seeker.png");
  load_texture(EnemyName::SUCCUBUS, "stage_2/succubus.png");
  load_texture(EnemyName::OGRE, "stage_2/ogre.png");
  load_texture(EnemyName::BLOOD_FERAL, "stage_2/blood_feral.png");
  load_texture(EnemyName::DARK_QUEEN_YOA, "stage_2/dark_queen_yoa.png");
  load_texture(EnemyName::KNIGHT_REMMENT, "stage_2/knight_remment.png");
  // Stage 3
  load_texture(EnemyName::EARTH_BULL, "stage_3/earth_bull.png");
  load_texture(EnemyName::BUSH_WISP, "stage_3/bush_wisp.png");
  load_texture(EnemyName::LEAF_IMP, "stage_3/leaf_imp.png");
  load_texture(EnemyName::EARTH_LION, "stage_3/earth_lion.png");
  load_texture(EnemyName::MANDRAKE, "stage_3/mandrake.png");
  load_texture(EnemyName::ROCK_GOLEM, "stage_3/rock_golem.png");
  load_texture(EnemyName::EARTH_SNAKE, "stage_3/earth_snake.png");
  load_texture(EnemyName::EARTH_SPAWN, "stage_3/earth_spawn.png");
  load_texture(EnemyName::EARTH_TURTLE, "stage_3/earth_turtle.png");
  load_texture(EnemyName::EARTH_WISP, "stage_3/earth_wisp.png");
  load_texture(EnemyName::QUEEN_RAFFLESIA, "stage_3/queen_rafflesia.png");
  load_texture(EnemyName::QUEEN_YGGDRASIL, "stage_3/queen_yggdrasil.png");
  load_texture(EnemyName::GEMSTONE_GOLEM, "stage_3/gemstone_golem.png");
  // Stage 4
  load_texture(EnemyName::GOBLIN_ARCHER, "stage_4/goblin_archer.png");
  load_texture(EnemyName::GOBLIN_ELITE, "stage_4/goblin_elite.png");
  load_texture(EnemyName::GOBLIN_GRUNT, "stage_4/goblin_grunt.png");
  load_texture(EnemyName::GOBLIN_MAGE, "stage_4/goblin_mage.png");
  load_texture(EnemyName::GOBLIN_RAIDER, "stage_4/goblin_raider.png");
  load_texture(EnemyName::ROGUE_SWORDMAN, "stage_4/rogue_swordman.png");
  load_texture(EnemyName::ROGUE_MONK, "stage_4/rogue_monk.png");
  load_texture(EnemyName::ROGUE_ASSASSIN, "stage_4/rogue_assassin.png");
  load_texture(EnemyName::BONEMASK, "stage_4/bonemask.png");
  load_texture(EnemyName::THE_FALLEN, "stage_4/the_fallen.png");
  load_texture(EnemyName::ANCIENT_AUTOMATON, "stage_4/ancient_automaton.png");
  // Stage 5
  load_texture(EnemyName::ELF_ARCHER, "stage_5/elf_archer.png");
  load_texture(EnemyName::ELF_ASSASSIN, "stage_5/elf_assassin.png");
  load_texture(EnemyName::CROSSBOW_ELF, "stage_5/crossbow_elf.png");
  load_texture(EnemyName::DUAL_SWORD_ELF, "stage_5/dual_sword_elf.png");
  load_texture(EnemyName::ELF_MAGE, "stage_5/elf_mage.png");
  load_texture(EnemyName::SPEAR_ELF, "stage_5/spear_elf.png");
  load_texture(EnemyName::SWORD_ELF, "stage_5/sword_elf.png");
  load_texture(EnemyName::NATURE_LINKER, "stage_5/nature_linker.png");
  load_texture(EnemyName::ROGUE_ELF, "stage_5/rogue_elf.png");
  load_texture(EnemyName::SPELLCASTER, "stage_5/spellcaster.png");
  load_texture(EnemyName::CELESTIAL_BEATRIX, "stage_5/celestial_beatrix.png");
  load_texture(EnemyName::ALFADRIEL, "stage_5/alfadriel.png");
  load_texture(EnemyName::SON_OF_VALHALLA, "stage_5/son_of_valhalla.png");
  // Stage 6
  load_texture(EnemyName::GAZERS_EYEWING, "stage_6/gazers_eyewing.png");
  load_texture(EnemyName::GAZERS_SKULL, "stage_6/gazers_skull.png");
  load_texture(EnemyName::TENTEYE, "stage_6/tenteye.png");
  load_texture(EnemyName::GHOSTUS, "stage_6/ghostus.png");
  load_texture(EnemyName::KNIGHT_DESTRAND, "stage_6/knight_destrand.png");
  load_texture(EnemyName::KNIGHT_GALPHA, "stage_6/knight_galpha.png");
  load_texture(EnemyName::KNIGHT_GOLIATH, "stage_6/knight_goliath.png");
  load_texture(EnemyName::GHOST_PUPPET_PAILO, "stage_6/ghost_puppet_pailo.png");
  load_texture(EnemyName::GHOST_REVELATOR, "stage_6/ghost_revelator.png");
  load_texture(EnemyName::ASTRAL_LICH, "stage_6/astral_lich.png");
  load_texture(EnemyName::ELDRITCH_GOD, "stage_6/eldritch_god.png");
  load_texture(EnemyName::REAPER_NIHILO, "stage_6/reaper_nihilo.png");
  // Stage 7
  load_texture(EnemyName::AXE_KNIGHT, "stage_7/axe_knight.png");
  load_texture(EnemyName::GOLDEN_AXE_KNIGHT, "stage_7/golden_axe_knight.png");
  load_texture(EnemyName::GUNNER_KNIGHT, "stage_7/gunner_knight.png");
  load_texture(EnemyName::GOLDEN_GUNNER_KNIGHT,
               "stage_7/golden_gunner_knight.png");
  load_texture(EnemyName::SPEAR_KNIGHT, "stage_7/spear_knight.png");
  load_texture(EnemyName::GOLDEN_SPEAR_KNIGHT,
               "stage_7/golden_spear_knight.png");
  load_texture(EnemyName::SWORD_KNIGHT, "stage_7/sword_knight.png");
  load_texture(EnemyName::GOLDEN_SWORD_KNIGHT,
               "stage_7/golden_sword_knight.png");
  load_texture(EnemyName::GOLDEN_HUANGLONG, "stage_7/golden_huanglong.png");
  load_texture(EnemyName::GOLDEN_LADON, "stage_7/golden_ladon.png");
  load_texture(EnemyName::GOLDEN_EMPEROR, "stage_7/golden_emperor.png");
  // Stage 8
  load_texture(EnemyName::FIRE_BULL, "stage_8/fire_bull.png");
  load_texture(EnemyName::FIRE_DRAGONSPAWN, "stage_8/fire_dragonspawn.png");
  load_texture(EnemyName::FIRE_LION, "stage_8/fire_lion.png");
  load_texture(EnemyName::FIRE_OGRE, "stage_8/fire_ogre.png");
  load_texture(EnemyName::FIRE_SABRETOOTH, "stage_8/fire_sabretooth.png");
  load_texture(EnemyName::FIRE_SALAMANDER, "stage_8/fire_salamander.png");
  load_texture(EnemyName::FIRE_TURTLE, "stage_8/fire_turtle.png");
  load_texture(EnemyName::VOLCANIC_MAIDEN, "stage_8/volcanic_maiden.png");
  load_texture(EnemyName::FIRE_VULTURE, "stage_8/fire_vulture.png");
  load_texture(EnemyName::FIRE_WISP, "stage_8/fire_wisp.png");
  load_texture(EnemyName::NUCKELAVEE, "stage_8/nuckelavee.png");
  load_texture(EnemyName::ILNOCT, "stage_8/ilnoct.png");
  load_texture(EnemyName::HELLHOUND_GARM, "stage_8/hellhound_garm.png");

  load_texture(ResourceName::PIERCED_SKULL_TEXTURE, "img/pierced_skull.png");
  load_texture(ResourceName::PLAYER_TEXTURE, "img/player.png");
  load_texture(ResourceName::COIN_TEXTURE_1, "img/money/money_1.png");
  load_texture(ResourceName::COIN_TEXTURE_2, "img/money/money_2.png");
  load_texture(ResourceName::COIN_TEXTURE_3, "img/money/money_3.png");
  load_texture(ResourceName::COIN_TEXTURE_4, "img/money/money_4.png");
  load_texture(ResourceName::COIN_TEXTURE_5, "img/money/money_5.png");
  load_texture(ResourceName::COIN_TEXTURE_6, "img/money/money_6.png");
  load_texture(ResourceName::COIN_TEXTURE_7, "img/money/money_7.png");
  load_texture(ResourceName::COIN_TEXTURE_8, "img/money/money_8.png");
  load_texture(ResourceName::COIN_TEXTURE_9, "img/money/money_9.png");

  enemy_names = {
      // Stage 1
      {EnemyName::FAIRY_FILIA, "Fairy Filia"},
      {EnemyName::GRASSHOPPER, "Grasshopper"},
      {EnemyName::GREEN_SPIDER, "Green Spider"},
      {EnemyName::IMPERIAL_WIDOW, "Imperial Widow"},
      {EnemyName::MOTHY, "Mothy"},
      {EnemyName::SHROOMY, "Shroomy"},
      {EnemyName::SPORA, "Spora"},
      {EnemyName::RUKKHA, "Rukkha"},
      {EnemyName::DAIDARABOTCHI, "Daidarabotchi"},
      {EnemyName::TELLIA, "Tellia"},
      // Stage 2
      {EnemyName::DARK_ANGEL, "Dark Angel"},
      {EnemyName::REAPER, "Reaper"},
      {EnemyName::BANSHEE, "Banshee"},
      {EnemyName::IMP, "Imp"},
      {EnemyName::GHAUL, "Ghaul"},
      {EnemyName::SEEKER, "Seeker"},
      {EnemyName::SUCCUBUS, "Succubus"},
      {EnemyName::OGRE, "Ogre"},
      {EnemyName::BLOOD_FERAL, "Blood Feral"},
      {EnemyName::DARK_QUEEN_YOA, "Dark Queen Yoa"},
      {EnemyName::KNIGHT_REMMENT, "Fairy Filia"},
      // Stage 3
      {EnemyName::EARTH_BULL, "Earth Bull"},
      {EnemyName::BUSH_WISP, "Bush Wisp"},
      {EnemyName::LEAF_IMP, "Leaf Imp"},
      {EnemyName::EARTH_LION, "Earth Lion"},
      {EnemyName::MANDRAKE, "Mandrake"},
      {EnemyName::ROCK_GOLEM, "Rock Golem"},
      {EnemyName::EARTH_SNAKE, "Earth Snake"},
      {EnemyName::EARTH_SPAWN, "Earth Spawn"},
      {EnemyName::EARTH_TURTLE, "Earth Turtle"},
      {EnemyName::EARTH_WISP, "Earth Wisp"},
      {EnemyName::QUEEN_RAFFLESIA, "Queen Rafflesia"},
      {EnemyName::QUEEN_YGGDRASIL, "Queen Yggdrasil"},
      {EnemyName::GEMSTONE_GOLEM, "Gemstone Golem"},
      // Stage 4
      {EnemyName::GOBLIN_ARCHER, "Goblin Archer"},
      {EnemyName::GOBLIN_ELITE, "Goblin Elite"},
      {EnemyName::GOBLIN_GRUNT, "Goblin Grunt"},
      {EnemyName::GOBLIN_MAGE, "Goblin Mage"},
      {EnemyName::GOBLIN_RAIDER, "Goblin Raider"},
      {EnemyName::ROGUE_SWORDMAN, "Rogue Swordman"},
      {EnemyName::ROGUE_MONK, "Rogue Monk"},
      {EnemyName::ROGUE_ASSASSIN, "Rogue Assassin"},
      {EnemyName::BONEMASK, "Bonemask"},
      {EnemyName::THE_FALLEN, "The Fallen"},
      {EnemyName::ANCIENT_AUTOMATON, "Ancient Automaton"},
      // Stage 5
      {EnemyName::ELF_ARCHER, "Elf Archer"},
      {EnemyName::ELF_ASSASSIN, "Elf Assassin"},
      {EnemyName::CROSSBOW_ELF, "Crossbow Elf"},
      {EnemyName::DUAL_SWORD_ELF, "Dual Sword Elf"},
      {EnemyName::ELF_MAGE, "Elf Mage"},
      {EnemyName::SPEAR_ELF, "Spear Elf"},
      {EnemyName::SWORD_ELF, "Sword Elf"},
      {EnemyName::NATURE_LINKER, "Nature Linker"},
      {EnemyName::ROGUE_ELF, "Rogue Elf"},
      {EnemyName::SPELLCASTER, "Spellcaster"},
      {EnemyName::CELESTIAL_BEATRIX, "Celestial Beatrix"},
      {EnemyName::ALFADRIEL, "Alfadriel"},
      {EnemyName::SON_OF_VALHALLA, "Son of Valhalla"},
      // Stage 6
      {EnemyName::GAZERS_EYEWING, "Gazers Eyewing"},
      {EnemyName::GAZERS_SKULL, "Gazers Skull"},
      {EnemyName::TENTEYE, "Tenteye"},
      {EnemyName::GHOSTUS, "Ghostus"},
      {EnemyName::KNIGHT_DESTRAND, "Knight Destrand"},
      {EnemyName::KNIGHT_GALPHA, "Knight Galpha"},
      {EnemyName::KNIGHT_GOLIATH, "Knight Goliath"},
      {EnemyName::GHOST_PUPPET_PAILO, "Ghost Puppet Pailo"},
      {EnemyName::GHOST_REVELATOR, "Ghost Revelator"},
      {EnemyName::ASTRAL_LICH, "Astral Lich"},
      {EnemyName::ELDRITCH_GOD, "Eldritch God"},
      {EnemyName::REAPER_NIHILO, "Reaper Nihilo"},
      // Stage 7
      {EnemyName::AXE_KNIGHT, "Axe Knight"},
      {EnemyName::GOLDEN_AXE_KNIGHT, "Golden Axe Knight"},
      {EnemyName::GUNNER_KNIGHT, "Gunner Knight"},
      {EnemyName::GOLDEN_GUNNER_KNIGHT, "Golden Gunner Knight"},
      {EnemyName::SPEAR_KNIGHT, "Spear Knight"},
      {EnemyName::GOLDEN_SPEAR_KNIGHT, "Golden Spear Knight"},
      {EnemyName::SWORD_KNIGHT, "Sword Knight"},
      {EnemyName::GOLDEN_SWORD_KNIGHT, "Golden Sword Knight"},
      {EnemyName::GOLDEN_HUANGLONG, "Golden Huanglong"},
      {EnemyName::GOLDEN_LADON, "GOlden Ladon"},
      {EnemyName::GOLDEN_EMPEROR, "Golden Emperor"},
      // Stage 8
      {EnemyName::FIRE_BULL, "Fire Bull"},
      {EnemyName::FIRE_DRAGONSPAWN, "Fire Dragonspawn"},
      {EnemyName::FIRE_LION, "Fire Lion"},
      {EnemyName::FIRE_OGRE, "Fire Ogre"},
      {EnemyName::FIRE_SABRETOOTH, "Fire Sabretooth"},
      {EnemyName::FIRE_SALAMANDER, "Fire Salamander"},
      {EnemyName::FIRE_TURTLE, "Fire Turtle"},
      {EnemyName::VOLCANIC_MAIDEN, "Volcanic Maiden"},
      {EnemyName::FIRE_VULTURE, "Fire Vulture"},
      {EnemyName::FIRE_WISP, "Fire Wisp"},
      {EnemyName::NUCKELAVEE, "Nuckelavee"},
      {EnemyName::ILNOCT, "Ilnoct"},
      {EnemyName::HELLHOUND_GARM, "Hellhound Garm"},
  };

  stage_names = {
      {StageName::GREEN_FOREST, "Green Forest"},
      {StageName::DARK_FOREST, "Dark Forest"},
      {StageName::MAGIC_FOREST, "Magic Forest"},
      {StageName::CITY_ENTRANCE, "City Entrance"},
      {StageName::FORGOTTEN_ROAD, "Forgotten Road"},
      {StageName::HAUNTED_MARKETPLACE, "Haunted Marketplace"},
      {StageName::GOLDEN_TEMPLE, "Golden Temple"},
      {StageName::INFERNO, "Inferno"},
  };
}

sf::Texture &Resources::get_texture(StageName stage_name)
{
  auto pair = background_textures.find(stage_name);
  return *pair->second;
}

sf::Texture &Resources::get_texture(EnemyName enemy_name)
{
  auto pair = enemy_textures.find(enemy_name);
  return *pair->second;
}

sf::Font &Resources::get_font(ResourceName resource_name)
{
  auto pair = fonts.find(resource_name);
  return *pair->second;
}

void Resources::load_texture(StageName stage_name, const std::string &file_name)
{
  std::unique_ptr<sf::Texture> texture(new sf::Texture());
  std::string path = resources_path + "img/background/" + file_name;
  texture->loadFromFile(path);
  background_textures.insert(std::make_pair(stage_name, std::move(texture)));
}

void Resources::load_texture(EnemyName enemy_name, const std::string &file_name)
{
  std::unique_ptr<sf::Texture> texture(new sf::Texture());
  std::string path = resources_path + "img/enemies/" + file_name;
  texture->loadFromFile(path);
  texture->setSmooth(true);
  enemy_textures.insert(std::make_pair(enemy_name, std::move(texture)));
}

void Resources::load_font(ResourceName resource_name,
                          const std::string &file_name)
{
  std::unique_ptr<sf::Font> font(new sf::Font());
  std::string path = resources_path + "font/" + file_name;
  font->loadFromFile(path);
  fonts.insert(std::make_pair(resource_name, std::move(font)));
}

void Resources::load_texture(ResourceName resource_name,
                             const std::string &file_name)
{
  std::unique_ptr<sf::Texture> texture(new sf::Texture());
  std::string path = resources_path + file_name;
  texture->loadFromFile(path);
  texture->setSmooth(true);
  other_textures.insert(std::make_pair(resource_name, std::move(texture)));
}

sf::Texture &Resources::get_texture(ResourceName resource_name)
{
  auto pair = other_textures.find(resource_name);
  return *pair->second;
}

std::string &Resources::get_name(const EnemyName &enemy_name)
{
  return enemy_names[enemy_name];
}

std::string &Resources::get_name(const StageName &stage_name)
{
  return stage_names[stage_name];
}
