#define private public

#include "../src/animator.h"
#include <catch2/catch.hpp>

namespace animator_test
{
std::unique_ptr<sf::RenderWindow> w = std::make_unique<sf::RenderWindow>(
    sf::VideoMode(1, 1, 32), "t", sf::Style::None);
Resources r{};
Player p{r};
Enemy e{r};
Stage s{r};

TEST_CASE("Sprites are scaled correctly", "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.scale(e.sprite, 1.05f);
  REQUIRE(e.sprite.getScale().x == Approx(2.9f));
}

TEST_CASE("Hovered sprites should be scaled up", "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.hover_animation_states[&e.sprite] = true;
  animator.scale_hovered();
  float original_scale = animator.original_scales[&e.sprite].x;
  float current_scale = e.sprite.getScale().x;
  REQUIRE(current_scale > original_scale);
}

TEST_CASE("Non-hovered sprites should not be scaled up", "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.scale_hovered();
  float original_scale = animator.original_scales[&e.sprite].x;
  float current_scale = e.sprite.getScale().x;
  REQUIRE(current_scale == original_scale);
}

TEST_CASE("Non-hovered sprites should return to their original value",
          "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.hover_animation_states[&e.sprite] = true;
  animator.scale_hovered();
  animator.hover_animation_states[&e.sprite] = false;
  animator.scale_hovered();
  float original_scale = animator.original_scales[&e.sprite].x;
  float current_scale = e.sprite.getScale().x;
  REQUIRE(current_scale == original_scale);
}

TEST_CASE("Clicked sprites should be assigned new frames to draw", "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.set_clicked_state(e.sprite);
  REQUIRE(animator.click_animation_states[&e.sprite] ==
          animator.click_animation_frames);
}

TEST_CASE(
    "Clicked sprites should be scaled up for each frame in the first half",
    "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.click_animation_states[&e.sprite] = animator.click_animation_frames;
  animator.scale_clicked();
  float original_scale = animator.original_scales[&e.sprite].x;
  float current_scale = e.sprite.getScale().x;
  REQUIRE(current_scale > original_scale);
}

TEST_CASE(
    "Clicked sprites should be scaled down for each frame in the second half",
    "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.click_animation_states[&e.sprite] =
      animator.click_animation_frames / 2;
  animator.scale_clicked();
  float original_scale = animator.original_scales[&e.sprite].x;
  float current_scale = e.sprite.getScale().x;
  REQUIRE(current_scale < original_scale);
}

TEST_CASE("Clicked sprites should not be scaled if there are no frames left",
          "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.click_animation_states[&e.sprite] = 0;
  animator.scale_clicked();
  float original_scale = animator.original_scales[&e.sprite].x;
  float current_scale = e.sprite.getScale().x;
  REQUIRE(current_scale == original_scale);
}

TEST_CASE("Dead sprites should be assigned new frames to draw", "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.set_dead_state(e.sprite);
  REQUIRE(animator.death_animation_states[&e.sprite] ==
          animator.death_animation_frames);
}

TEST_CASE("Dead sprites should not be assigned new frames if there are some "
          "still left to render",
          "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.set_dead_state(e.sprite);
  for (int i = 0; i < 5; ++i)
  {
    animator.draw_dead_sprites();
  }
  animator.set_dead_state(e.sprite);
  REQUIRE(animator.death_animation_states[&e.sprite] ==
          animator.death_animation_frames - 5);
}

TEST_CASE("When a sprite is set as dead, their related entity should be set to "
          "'regenerating'",
          "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.set_dead_state(e.sprite);
  REQUIRE(e.regenerating);
}

TEST_CASE(
    "Dead sprites should be scaled and moved up in the first 60% of the frames",
    "[animator]")
{
  Animator animator{w, r, p, e, s};
  float original_scale = e.sprite.getScale().x;
  float original_pos_x = e.sprite.getPosition().x;
  float original_pos_y = e.sprite.getPosition().y;
  animator.death_animation_states[&e.sprite] = animator.death_animation_frames;

  int frames = static_cast<int>(animator.death_animation_frames * 60 / 100);
  for (int i = 0; i < frames; i++)
  {
    animator.draw_dead_sprites();
  }

  float current_scale = e.sprite.getScale().x;
  float current_pos_x = e.sprite.getPosition().x;
  float current_pos_y = e.sprite.getPosition().y;
  REQUIRE(current_scale > original_scale);
  REQUIRE(current_pos_x > original_pos_x);
  REQUIRE(current_pos_y < original_pos_y);
}

TEST_CASE("Dead sprites should be scaled and moved down in the last 40% of the "
          "frames",
          "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.death_animation_states[&e.sprite] = animator.death_animation_frames;

  int start_frames =
      static_cast<int>(animator.death_animation_frames * 60 / 100);
  for (int i = 0; i < start_frames; i++)
  {
    animator.draw_dead_sprites();
  }

  float original_scale = e.sprite.getScale().x;
  float original_pos_y = e.sprite.getPosition().y;

  int end_frames = static_cast<int>(animator.death_animation_frames * 40 / 100);
  for (int i = 0; i < end_frames; i++)
  {
    animator.draw_dead_sprites();
  }

  float current_scale = e.sprite.getScale().x;
  float current_pos_y = e.sprite.getPosition().y;
  REQUIRE(current_scale < original_scale);
  REQUIRE(current_pos_y > original_pos_y);
}

TEST_CASE("When animating dead sprites, the last frame should trigger the "
          "regeneration of the related entity",
          "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.death_animation_states[&e.sprite] = 1;
  e.hp = 0;
  animator.draw_dead_sprites();
  REQUIRE(e.hp == e.max_hp);
}

TEST_CASE(
    "When animating dead sprites, the last frame should reset the rotation",
    "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.death_animation_states[&e.sprite] = 1;
  e.sprite.setRotation(5.0f);
  animator.draw_dead_sprites();
  REQUIRE(e.sprite.getRotation() == 0);
}

TEST_CASE("Damage bubbles should be added correctly", "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.add_damage_bubble(50);
  REQUIRE(animator.damage_bubbles.size() == 1);
  REQUIRE(
      animator.damage_bubbles.back().damage_text.getString().toAnsiString() ==
      "50");
}

TEST_CASE("Damage bubbles should have all of their frames drawn", "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.add_damage_bubble(50);
  int frames = animator.damage_bubbles.back().total_frames;
  for (int i = 0; i < frames; ++i)
  {
    animator.draw_damage_bubbles();
  }
  REQUIRE(animator.damage_bubbles.back().remaining_frames == 0);
}

TEST_CASE("Multiple damage bubbles should be drawn independently", "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.add_damage_bubble(50);
  for (int i = 0; i < 3; ++i)
    animator.draw_damage_bubbles();

  animator.add_damage_bubble(50);
  for (int i = 0; i < 3; ++i)
    animator.draw_damage_bubbles();

  animator.add_damage_bubble(50);

  const int total_frames = animator.damage_bubbles.back().total_frames;
  REQUIRE(animator.damage_bubbles.back().remaining_frames == total_frames);
  REQUIRE(animator.damage_bubbles.at(1).remaining_frames == total_frames - 3);
  REQUIRE(animator.damage_bubbles.front().remaining_frames == total_frames - 6);
}

TEST_CASE("Damage bubbles should be erased from the vector when all of their "
          "frames have been drawn",
          "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.add_damage_bubble(50);
  int frames = animator.damage_bubbles.back().total_frames;
  for (int i = 0; i < frames + 1; ++i)
  {
    animator.draw_damage_bubbles();
  }
  REQUIRE(animator.damage_bubbles.empty());
}

TEST_CASE("When money is added, between 2 to 7 coins should be drawn",
          "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.add_dropped_money(50);
  REQUIRE((animator.dropped_money.size() >= 2 &&
           animator.dropped_money.size() <= 7));
}

TEST_CASE("Each money drop should have all of its frames drawn", "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.add_dropped_money(50);
  int frames = animator.dropped_money.back().total_frames;
  for (int i = 0; i < frames; ++i)
  {
    animator.draw_dropped_money();
  }
  REQUIRE(animator.dropped_money.back().remaining_frames == 0);
}

TEST_CASE("Money drops should be erased from the vector when all of their "
          "frames have been drawn",
          "[animator]")
{
  Animator animator{w, r, p, e, s};
  animator.add_dropped_money(50);
  Money &original_back = animator.dropped_money.back();
  int frames = original_back.total_frames;
  for (int i = 0; i < frames + 3; ++i)
  {
    animator.draw_dropped_money();
  }
  REQUIRE(&animator.dropped_money.back() != &original_back);
}

} // namespace animator_test