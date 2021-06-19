#include "animator.h"
#include <random>

Animator::Animator(std::unique_ptr<sf::RenderWindow> &w, Resources &res,
                   Inventory &inv, Player &p, Enemy &e, Stage &s)
    : window(w), resources(res), inventory(inv), player(p), enemy(e), stage(s)
{
  hover_animation_states.emplace(&enemy.get_sprite(), false);
  click_animation_states.emplace(&enemy.get_sprite(), 0);
  death_animation_states.emplace(&enemy.get_sprite(), 0);
  original_scales.emplace(&enemy.get_sprite(), enemy.get_sprite().getScale());
  hover_scale_increases.emplace(&enemy.get_sprite(), 0.0f);
  click_scale_increases.emplace(&enemy.get_sprite(), 0.0f);
  hover_animation_states.emplace(&player.get_sprite(), false);
  click_animation_states.emplace(&player.get_sprite(), 0);
  death_animation_states.emplace(&player.get_sprite(), 0);
  hover_scale_increases.emplace(&player.get_sprite(), 0.0f);
  click_scale_increases.emplace(&player.get_sprite(), 0.0f);
  original_scales.emplace(&player.get_sprite(), player.get_sprite().getScale());
}

void Animator::animate()
{
  float delta_time = delta_clock.restart().asSeconds();
  elapsed_time += delta_time;
  while (elapsed_time >= time_per_frame)
  {
    refresh_hover_states();
    scale_hovered();
    scale_clicked();
    draw_damage_bubbles();
    draw_dead_sprites();
    draw_dropped_money();
    elapsed_time -= time_per_frame;
  }
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
  for (const auto &pair : hover_animation_states)
  {
    auto sprite = pair.first;
    auto should_animate = pair.second;

    const float max_scale = 0.05f;
    float &current_scale = hover_scale_increases[sprite];
    float increment = max_scale / hover_animation_frames;

    if (should_animate && current_scale < max_scale)
    {
      current_scale += increment;
      scale(*sprite, increment);
    }
    else if (!should_animate && current_scale > 0.0f)
    {
      current_scale -= increment;
      scale(*sprite, -increment);
    }
  }
}

void Animator::scale_clicked()
{
  const float max_scale = 0.06f;
  const float increment = max_scale / click_animation_frames;

  for (auto &pair : click_animation_states)
  {
    auto &frames_left = pair.second;
    if (frames_left == 0)
      continue;

    auto sprite = pair.first;
    float &current_scale = click_scale_increases[sprite];

    if (frames_left > click_animation_frames / 2 && current_scale < max_scale)
    {
      current_scale += increment;
      scale(*sprite, increment);
    }
    else
    {
      current_scale -= increment;
      scale(*sprite, -increment);
    }
    frames_left--;
  }
}

void Animator::add_damage_bubble(const long double &damage)
{
  damage_bubbles.emplace_back(DamageBubble{damage, resources});
}

void Animator::add_dropped_money(const double &value)
{
  static std::random_device random_device;
  static std::mt19937 rng(random_device());
  std::uniform_int_distribution<int> dist(2, 7);

  const int coin_count = dist(rng);

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
    int &frames_left = pair.second;

    if (frames_left == 0)
      continue;

    sf::Sprite *sprite = pair.first;

    if (frames_left == 1)
    {
      if (sprite == &enemy.get_sprite())
        enemy.regenerate(stage.get_name(), 1, false);

      if (sprite == &player.get_sprite())
        player.regenerate();

      sprite->setRotation(0.0f);
    }

    if (frames_left > 1)
    {
      const int start_frames = death_animation_frames * 70 / 100;

      if (death_animation_frames - frames_left < start_frames)
      {
        const double rotation_diff = 2.0f;
        const double position_x_diff = 10.5f;
        const double position_y_diff = -7.5f;
        const double scale_diff = 0.015f;

        sprite->rotate(static_cast<float>(rotation_diff));
        sprite->move(static_cast<float>(position_x_diff),
                     static_cast<float>(position_y_diff));
        scale(*sprite, static_cast<float>(scale_diff));
      }
      else
      {
        const double position_x_diff = -3.5f;
        const double position_y_diff = 3.5f;
        const double scale_diff = -0.1035f;

        sprite->move(static_cast<float>(position_x_diff),
                     static_cast<float>(position_y_diff));
        scale(*sprite, static_cast<float>(scale_diff));
      }
    }
    frames_left--;
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
