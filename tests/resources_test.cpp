#include "../src/gui/resources.h"
#include <catch2/catch_test_macros.hpp>

Resources resources{};

TEST_CASE("Resources are loaded", "[resources]")
{
  REQUIRE(resources.get_name(EnemyName::FAIRY_FILIA) == "Fairy Filia");
  REQUIRE(resources.get_name(EnemyName::DAIDARABOTCHI) == "Daidarabotchi");
  REQUIRE(resources.get_name(EnemyName::FIRE_SALAMANDER) == "Fire Salamander");

  REQUIRE(resources.get_texture(StageName::GREEN_FOREST).getSize() ==
          sf::Vector2<unsigned int>(1920, 1080));
  REQUIRE(resources.get_texture(StageName::HAUNTED_MARKETPLACE).getSize() ==
          sf::Vector2<unsigned int>(1920, 1080));
  REQUIRE(resources.get_texture(StageName::DARK_FOREST).getSize() ==
          sf::Vector2<unsigned int>(1920, 1080));

  REQUIRE(resources.get_texture(EnemyName::FAIRY_FILIA).getSize().x > 0);
  REQUIRE(resources.get_texture(EnemyName::FAIRY_FILIA).getSize().y > 0);
  REQUIRE(resources.get_texture(EnemyName::DAIDARABOTCHI).getSize().x > 0);
  REQUIRE(resources.get_texture(EnemyName::DAIDARABOTCHI).getSize().y > 0);
  REQUIRE(resources.get_texture(EnemyName::FIRE_SALAMANDER).getSize().x > 0);
  REQUIRE(resources.get_texture(EnemyName::FIRE_SALAMANDER).getSize().y > 0);

  REQUIRE(resources.get_texture(ResourceName::COIN_TEXTURE_1).getSize().x > 0);
  REQUIRE(resources.get_texture(ResourceName::COIN_TEXTURE_1).getSize().y > 0);
  REQUIRE(resources.get_texture(ResourceName::PLAYER_TEXTURE).getSize().x > 0);
  REQUIRE(resources.get_texture(ResourceName::PLAYER_TEXTURE).getSize().y > 0);

  REQUIRE(resources.get_font(ResourceName::GREAT_VIBES_FONT).getInfo().family ==
          "Great Vibes");
  REQUIRE(resources.get_font(ResourceName::RIGHTEOUS_FONT).getInfo().family ==
          "Righteous");
}