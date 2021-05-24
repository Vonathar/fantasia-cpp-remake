#include "damage_bubble.h"
#include "number_formatter.h"

DamageBubble::DamageBubble(const int &dmg, Resources &res)
{
  remaining_frames = 80;

  damage_text.setFont(res.get_font(ResourceName::RIGHTEOUS_FONT));
  damage_text.setCharacterSize(18);
  damage_text.setFillColor(sf::Color(255, 255, 255, 230));
  damage_text.setString(NumberFormatter::abbreviate(dmg));
  damage_text.setPosition(950.0f, 642.0f);
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

void DamageBubble::render(sf::RenderTarget &target)
{
  target.draw(bubble_rect);
  target.draw(damage_text);

  const float x_offset = -0.75f;
  const float y_offset = -1.5f;

  bubble_rect.move(x_offset, y_offset);
  damage_text.move(x_offset, y_offset);

  remaining_frames--;
}

bool DamageBubble::has_more_frames() const
{
  return remaining_frames > 0;
}