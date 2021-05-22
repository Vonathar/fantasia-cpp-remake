#include "enemy_generator.h"
#include <random>

EnemyGenerator::EnemyGenerator()
{
  stage_enemies = {
      // Stage 1
      {StageName::GREEN_FOREST,
       {EnemyName::FAIRY_FILIA, EnemyName::GRASSHOPPER, EnemyName::GREEN_SPIDER,
        EnemyName::IMPERIAL_WIDOW, EnemyName::MOTHY, EnemyName::SHROOMY,
        EnemyName::SPORA}},
      // Stage 2
      {StageName::DARK_FOREST,
       {EnemyName::DARK_ANGEL, EnemyName::REAPER, EnemyName::BANSHEE,
        EnemyName::IMP, EnemyName::GHAUL, EnemyName::SEEKER,
        EnemyName::SUCCUBUS, EnemyName::OGRE}},
      // Stage 3
      {StageName::MAGIC_FOREST,
       {EnemyName::EARTH_BULL, EnemyName::BUSH_WISP, EnemyName::LEAF_IMP,
        EnemyName::EARTH_LION, EnemyName::MANDRAKE, EnemyName::ROCK_GOLEM,
        EnemyName::EARTH_SNAKE, EnemyName::EARTH_SPAWN, EnemyName::EARTH_TURTLE,
        EnemyName::EARTH_WISP}},
      // Stage 4
      {StageName::CITY_ENTRANCE,
       {EnemyName::GOBLIN_ARCHER, EnemyName::GOBLIN_ELITE,
        EnemyName::GOBLIN_GRUNT, EnemyName::GOBLIN_MAGE,
        EnemyName::GOBLIN_RAIDER, EnemyName::ROGUE_SWORDMAN,
        EnemyName::ROGUE_MONK, EnemyName::ROGUE_ASSASSIN}},
      // Stage 5
      {StageName::FORGOTTEN_ROAD,
       {EnemyName::ELF_ARCHER, EnemyName::ELF_ASSASSIN, EnemyName::CROSSBOW_ELF,
        EnemyName::DUAL_SWORD_ELF, EnemyName::ELF_MAGE, EnemyName::SPEAR_ELF,
        EnemyName::SWORD_ELF, EnemyName::NATURE_LINKER, EnemyName::ROGUE_ELF,
        EnemyName::SPELLCASTER}},
      // Stage 6
      {StageName::HAUNTED_MARKETPLACE,
       {EnemyName::GAZERS_EYEWING, EnemyName::GAZERS_SKULL, EnemyName::TENTEYE,
        EnemyName::GHOSTUS, EnemyName::KNIGHT_DESTRAND,
        EnemyName::KNIGHT_GALPHA, EnemyName::KNIGHT_GOLIATH,
        EnemyName::GHOST_PUPPET_PAILO, EnemyName::GHOST_REVELATOR}},
      // Stage 7
      {StageName::GOLDEN_TEMPLE,
       {EnemyName::AXE_KNIGHT, EnemyName::GOLDEN_AXE_KNIGHT,
        EnemyName::GUNNER_KNIGHT, EnemyName::GOLDEN_GUNNER_KNIGHT,
        EnemyName::SPEAR_KNIGHT, EnemyName::GOLDEN_SPEAR_KNIGHT,
        EnemyName::SWORD_KNIGHT, EnemyName::GOLDEN_SWORD_KNIGHT}},
      // Stage 8
      {StageName::INFERNO,
       {EnemyName::FIRE_BULL, EnemyName::FIRE_DRAGONSPAWN, EnemyName::FIRE_LION,
        EnemyName::FIRE_OGRE, EnemyName::FIRE_SABRETOOTH,
        EnemyName::FIRE_SALAMANDER, EnemyName::FIRE_TURTLE,
        EnemyName::VOLCANIC_MAIDEN, EnemyName::FIRE_VULTURE,
        EnemyName::VOLCANIC_MAIDEN, EnemyName::FIRE_VULTURE,
        EnemyName::FIRE_WISP}}};
  stage_bosses = {
      // Stage 1
      {StageName::GREEN_FOREST,
       {EnemyName::RUKKHA, EnemyName::DAIDARABOTCHI, EnemyName::TELLIA}},
      // Stage 2
      {StageName::DARK_FOREST,
       {EnemyName::BLOOD_FERAL, EnemyName::DARK_QUEEN_YOA,
        EnemyName::KNIGHT_REMMENT}},
      // Stage 3
      {StageName::MAGIC_FOREST,
       {EnemyName::QUEEN_RAFFLESIA, EnemyName::QUEEN_YGGDRASIL,
        EnemyName::GEMSTONE_GOLEM}},
      // Stage 4
      {StageName::CITY_ENTRANCE,
       {EnemyName::BONEMASK, EnemyName::THE_FALLEN,
        EnemyName::ANCIENT_AUTOMATON}},
      // Stage 5
      {StageName::FORGOTTEN_ROAD,
       {EnemyName::CELESTIAL_BEATRIX, EnemyName::ALFADRIEL,
        EnemyName::SON_OF_VALHALLA}},
      // Stage 6
      {StageName::HAUNTED_MARKETPLACE,
       {EnemyName::ASTRAL_LICH, EnemyName::ELDRITCH_GOD,
        EnemyName::REAPER_NIHILO}},
      // Stage 7
      {StageName::GOLDEN_TEMPLE,
       {EnemyName::GOLDEN_HUANGLONG, EnemyName::GOLDEN_LADON,
        EnemyName::GOLDEN_EMPEROR}},
      // Stage 8
      {StageName::INFERNO,
       {EnemyName::NUCKELAVEE, EnemyName::ILNOCT, EnemyName::HELLHOUND_GARM}}};
}

const EnemyName &EnemyGenerator::get_random_enemy(const StageName &stage_name)
{
  static std::random_device random_device;
  static std::mt19937 rng(random_device());
  std::uniform_int_distribution<std::mt19937::result_type> dist(
      0, stage_enemies[stage_name].size() - 1);
  return stage_enemies[stage_name].at(dist(rng));
}

const EnemyName &EnemyGenerator::get_random_boss(const StageName &stage_name)
{
  static std::random_device random_device;
  static std::mt19937 rng(random_device());
  std::uniform_int_distribution<std::mt19937::result_type> dist(
      0, stage_bosses[stage_name].size() - 1);
  return stage_bosses[stage_name].at(dist(rng));
}
