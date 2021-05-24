#include "animator.h"

Animator::Animator(std::unique_ptr<sf::RenderWindow> &w,
                   sf::Sprite &player_sprite, sf::Sprite &enemy_sprite,
                   Resources &res)
    : window(w), resources(res)
{
  hover_animation_states.emplace(&enemy_sprite, false);
  click_animation_states.emplace(&enemy_sprite, 0);
  original_scales.emplace(&enemy_sprite, enemy_sprite.getScale());
  hover_animation_states.emplace(&player_sprite, false);
  click_animation_states.emplace(&player_sprite, 0);
  original_scales.emplace(&player_sprite, player_sprite.getScale());
}

void Animator::animate()
{
  refresh_hover_states();
  scale_hovered();
  scale_clicked();
  draw_damage_bubbles();
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

void Animator::set_clicked_state(sf::Sprite &sprite)
{
  click_animation_states[&sprite] = click_animation_frames;
}
