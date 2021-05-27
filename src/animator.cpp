#include "animator.h"
#include <cmath>

Animator::Animator(std::unique_ptr<sf::RenderWindow> &w, Resources &res,
                   Player &p, Enemy &e, Stage &s)
    : window(w), resources(res), player(p), enemy(e), stage(s)
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

void Animator::draw_dead_sprites()
{
  for (auto &pair : death_animation_states)
  {
    if (pair.second == 0)
      continue;

    const double start_frames = death_animation_frames / 6.0;
    const double end_frames = death_animation_frames / 4.0;

    if (pair.second >= start_frames)
    {
      const double rotation_diff = 0.2f * std::pow(pair.second, 0.13f);
      const double position_diff = 1.0f * std::pow(pair.second, 0.20f);
      const double scale_diff = 0.0023f * std::pow(pair.second, 0.14f);

      pair.first->rotate(static_cast<float>(rotation_diff));
      pair.first->move(static_cast<float>(position_diff),
                       static_cast<float>(-position_diff));
      scale(*pair.first, static_cast<float>(scale_diff));
    }

    if (pair.second > 1 && pair.second < end_frames)
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
      pair.first->setRotation(0.0f);
    }
    pair.second = pair.second - 1;
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
  }
}
