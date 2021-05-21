#include "animator.h"

Animator::Animator(std::unique_ptr<sf::RenderWindow> &w,
                   sf::Sprite &player_sprite, sf::Sprite &enemy_sprite)
    : window(w)
{
  animation_states.emplace(&enemy_sprite, false);
  original_scales.emplace(&enemy_sprite, enemy_sprite.getScale());
  animation_states.emplace(&player_sprite, false);
  original_scales.emplace(&player_sprite, player_sprite.getScale());
}

void Animator::animate()
{
  find_hovered_sprite();
  update_scales();
}

void Animator::find_hovered_sprite()
{
  sf::Vector2f mouse_pos =
      sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(*window).x),
                   static_cast<float>(sf::Mouse::getPosition(*window).y));
  for (auto &pair : animation_states)
  {
    pair.second = pair.first->getGlobalBounds().contains(mouse_pos);
  }
}

void Animator::update_scales()
{
  for (const auto &pair : animation_states)
  {
    auto sprite = pair.first;
    auto should_animate = pair.second;

    sf::Vector2f current_scale = sprite->getScale();
    sf::Vector2<unsigned int> current_size = sprite->getTexture()->getSize();

    if (should_animate)
    {
      if (current_scale.x < original_scales[sprite].x + 0.05f)
      {
        sprite->move(static_cast<float>(current_size.x) * -0.0025f,
                     static_cast<float>(current_size.y) * -0.005f);
        sprite->setScale(
            sf::Vector2f(current_scale.x + 0.005f, current_scale.y + 0.005f));
      }
    }
    else if (sprite->getScale().x > original_scales[sprite].x)
    {
      sprite->move(static_cast<float>(current_size.x) * 0.0025f,
                   static_cast<float>(current_size.y) * 0.005f);
      sprite->setScale(current_scale.x - 0.005f, current_scale.y - 0.005f);
    }
  }
}
