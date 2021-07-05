#include "damage_bubble.h"
#include "../../number_formatter.h"
#include <random>

DamageBubble::DamageBubble(const long double &dmg, Resources &res)
{
  remaining_frames = total_frames;

  static std::random_device random_device;
  static std::mt19937 rng(random_device());
  std::uniform_real_distribution<float> dist(-4.0, 4.0);
  x_offset = dist(rng);

  damage_text.setFont(res.get_font(ResourceName::SKRANJI_FONT));
  damage_text.setCharacterSize(18);
  damage_text.setFillColor(sf::Color(255, 255, 255, 230));
  damage_text.setString(NumberFormatter::abbreviate(dmg));
  damage_text.setPosition(
      static_cast<float>(sf::Mouse::getPosition().x) - 20.0f,
      static_cast<float>(sf::Mouse::getPosition().y) - 40.0f);
  bubble_rect.set_size(sf::Vector2f(damage_text.getLocalBounds().width * 2,
                                    damage_text.getLocalBounds().height * 2.5));
  bubble_rect.set_corners_radius(15);
  bubble_rect.set_corner_point_count(30);
  bubble_rect.setFillColor(sf::Color(0, 0, 0, 230));
  bubble_rect.setOutlineColor(sf::Color(255, 255, 255, 230));
  bubble_rect.setOutlineThickness(3);
  bubble_rect.setPosition(sf::Vector2f(
      damage_text.getPosition().x - damage_text.getLocalBounds().width / 2,
      damage_text.getPosition().y - damage_text.getLocalBounds().height / 2.5));
}

void DamageBubble::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (remaining_frames == 0)
    return;

  target.draw(bubble_rect, states);
  target.draw(damage_text, states);

  bubble_rect.move(x_offset, -4.0f);
  damage_text.move(x_offset, -4.0f);

  remaining_frames--;
}

bool DamageBubble::has_more_frames() const
{
  return remaining_frames > 0;
}
