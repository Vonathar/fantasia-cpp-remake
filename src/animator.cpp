#include "animator.h"
#include <cmath>
#include <random>

Animator::Animator(std::unique_ptr<sf::RenderWindow> &w, Resources &res,
                   Inventory &inv, Player &p, Enemy &e, Stage &s)
    : window(w), resources(res), inventory(inv), player(p), enemy(e), stage(s)
{
  hover_animation_states.emplace(&enemy.get_sprite(), false);
  click_animation_states.emplace(&enemy.get_sprite(), 0);
  death_animation_states.emplace(&enemy.get_sprite(), 0);
  original_scales.emplace(&enemy.get_sprite(), enemy.get_sprite().getScale());
  hover_animation_states.emplace(&player.get_sprite(), false);
  click_animation_states.emplace(&player.get_sprite(), 0);
  death_animation_states.emplace(&player.get_sprite(), 0);
  original_scales.emplace(&player.get_sprite(), player.get_sprite().getScale());
}

void Animator::animate()
{
  refresh_hover_states();
  scale_hovered();
  scale_clicked();
  draw_damage_bubbles();
  draw_dead_sprites();
  draw_dropped_money();
}

void Animator::refresh_hover_states()
{
  sf::Vector2f mouse_pos =
      sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(*window).x),
                   static_cast<float>(sf::Mouse::getPosition(*window).y));
  for (auto &pair : hover_animation_states)
  {
    pair.second = pair.first->getGlobalBounds().contains(mouse_pos);
  }
}

void Animator::scale(sf::Sprite &sprite, const float &increment)
{
  sf::Vector2f current_scale = sprite.getScale();
  sf::Vector2<unsigned int> current_size = sprite.getTexture()->getSize();

  sprite.move(static_cast<float>(current_size.x) * -increment,
              static_cast<float>(current_size.y) * -(increment * 2));
  sprite.setScale(sf::Vector2f(current_scale.x + (increment * 2),
                               current_scale.y + (increment * 2)));
}

void Animator::scale_hovered()
{
  const float max_scale_increase = 0.05f;
  const float frame_count = 40;
  const float increment = max_scale_increase / frame_count;

  for (const auto &pair : hover_animation_states)
  {
    auto sprite = pair.first;
    auto should_animate = pair.second;

    if (should_animate)
    {
      if (sprite->getScale().x < original_scales[sprite].x + max_scale_increase)
      {
        scale(*sprite, increment);
      }
    }
    else if (sprite->getScale().x > original_scales[sprite].x)
    {
      scale(*sprite, -increment);
    }
  }
}

void Animator::scale_clicked()
{
  const float max_scale_increase = 0.05f;
  const float increment = max_scale_increase / click_animation_frames;

  for (auto &pair : click_animation_states)
  {
    auto frames_left = pair.second;

    if (frames_left > click_animation_frames / 2)
    {
      scale(*pair.first, increment);
      pair.second = pair.second - 1;
    }
    else if (frames_left > 0)
    {
      scale(*pair.first, -increment);
      pair.second = pair.second - 1;
    }
  }
}

void Animator::add_damage_bubble(const int &damage)
{
  damage_bubbles.emplace_back(DamageBubble{damage, resources});
}

void Animator::add_dropped_money(const double &value)
{
  static std::random_device random_device;
  static std::mt19937 rng(random_device());
  std::uniform_int_distribution<int> dist(2, 7);

  int coin_count = dist(rng);

  for (int i = 0; i < coin_count; i++)
  {
    double coin_value = value / coin_count;

    if (i == 0)
      coin_value = coin_value * 0.7;
    if (i == coin_count - 1)
      coin_value = coin_value / 0.7;

    dropped_money.emplace_back(Money{coin_value, resources});
  }
}

void Animator::draw_damage_bubbles()
{
  for (auto it = damage_bubbles.begin(); it != damage_bubbles.end();)
  {
    if (it->has_more_frames())
    {
      it->render(*window);
      ++it;
    }
    else
      it = damage_bubbles.erase(it);
  }
}

void Animator::draw_dropped_money()
{
  for (auto it = dropped_money.begin(); it != dropped_money.end();)
  {
    if (it->has_more_frames())
    {
      it->render(*window);
      ++it;
    }
    else
    {
      inventory.add_money(it->get_value());
      it = dropped_money.erase(it);
    }
  }
}

void Animator::draw_dead_sprites()
{
  for (auto &pair : death_animation_states)
  {
    if (pair.second == 0)
      continue;

    const int start_frames = death_animation_frames * 60 / 100;

    if (death_animation_frames - pair.second < start_frames)
    {
      const double rotation_diff = 0.2f * std::pow(pair.second, 0.13f);
      const double position_diff = 1.0f * std::pow(pair.second, 0.20f);
      const double scale_diff = 0.0023f * std::pow(pair.second, 0.14f);

      pair.first->rotate(static_cast<float>(rotation_diff));
      pair.first->move(static_cast<float>(position_diff),
                       static_cast<float>(-position_diff));
      scale(*pair.first, static_cast<float>(scale_diff));
    }
    else
    {
      const double position_x_diff = -1.0f * std::pow(pair.second, 0.13f);
      const double position_y_diff = 1.0f;
      const double scale_diff = -0.0195f * std::pow(pair.second, 0.23f);

      pair.first->move(static_cast<float>(position_x_diff),
                       static_cast<float>(position_y_diff));
      scale(*pair.first, static_cast<float>(scale_diff));
    }
    if (pair.second == 1)
    {
      if (&enemy.get_sprite() == pair.first)
      {
        enemy.regenerate(stage.get_name(), 1, false);
      }
      if (&player.get_sprite() == pair.first)
      {
        player.regenerate();
      }
      pair.first->setRotation(0.0f);
    }
    pair.second--;
  }
}

void Animator::set_clicked_state(sf::Sprite &sprite)
{
  click_animation_states[&sprite] = click_animation_frames;
}

void Animator::set_dead_state(sf::Sprite &sprite)
{
  if (death_animation_states[&sprite] == 0)
  {
    death_animation_states[&sprite] = death_animation_frames;

    if (&enemy.get_sprite() == &sprite)
    {
      enemy.set_regenerating(true);
    }
    if (&player.get_sprite() == &sprite)
    {
      player.set_regenerating(true);
    }
  }
}
