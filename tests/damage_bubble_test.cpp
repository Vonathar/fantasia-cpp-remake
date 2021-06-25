#define private public

#include "../src/gui/animator.h"
#include <catch2/catch_test_macros.hpp>

namespace damage_bubble_test
{
std::unique_ptr<sf::RenderWindow> w = std::make_unique<sf::RenderWindow>(
    sf::VideoMode(1, 1, 32), "t", sf::Style::None);
Resources r{};

TEST_CASE("Damage bubbles should have a random x-position offset",
          "[damage_bubble]")
{
  DamageBubble damage_bubble{5, r};
  REQUIRE((damage_bubble.x_offset >= -4.0f && damage_bubble.x_offset <= 4.0f));
}

TEST_CASE("Damage bubbles should have all frames available when initialised",
          "[damage_bubble]")
{
  DamageBubble damage_bubble{5, r};
  REQUIRE(damage_bubble.remaining_frames == damage_bubble.total_frames);
}

TEST_CASE("Damage bubbles should have one less frame after each render",
          "[damage_bubble]")
{
  DamageBubble damage_bubble{5, r};
  w->draw(damage_bubble);
  REQUIRE(damage_bubble.remaining_frames == damage_bubble.total_frames - 1);
}

TEST_CASE("Damage bubbles should change their position after each render",
          "[damage_bubble]")
{
  DamageBubble damage_bubble{5, r};

  sf::Vector2f starting_position_rect = damage_bubble.bubble_rect.getPosition();
  sf::Vector2f starting_position_text = damage_bubble.damage_text.getPosition();
  w->draw(damage_bubble);
  sf::Vector2f current_position_rect = damage_bubble.bubble_rect.getPosition();
  sf::Vector2f current_position_text = damage_bubble.damage_text.getPosition();

  REQUIRE(current_position_rect.x != starting_position_rect.x);
  REQUIRE(current_position_rect.y != starting_position_rect.y);
  REQUIRE(current_position_text.x != starting_position_text.x);
  REQUIRE(current_position_text.y != starting_position_text.y);
}

TEST_CASE("Damage bubbles should not render if there are no frames left",
          "[damage_bubble]")
{
  DamageBubble damage_bubble{5, r};
  damage_bubble.remaining_frames = 0;

  sf::Vector2f starting_position_rect = damage_bubble.bubble_rect.getPosition();
  sf::Vector2f starting_position_text = damage_bubble.damage_text.getPosition();
  w->draw(damage_bubble);
  sf::Vector2f current_position_rect = damage_bubble.bubble_rect.getPosition();
  sf::Vector2f current_position_text = damage_bubble.damage_text.getPosition();
  REQUIRE(starting_position_rect.x == current_position_rect.x);
  REQUIRE(starting_position_rect.y == current_position_rect.y);
  REQUIRE(starting_position_text.x == current_position_text.x);
  REQUIRE(starting_position_text.y == current_position_text.y);
  REQUIRE(damage_bubble.remaining_frames == 0);
}

} // namespace damage_bubble_test