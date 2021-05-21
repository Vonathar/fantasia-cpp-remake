#include "rounded_rect.h"
#include <cmath>

RoundedRect::RoundedRect(const sf::Vector2f &size, float radius,
                         unsigned int corner_point_count)
    : size(size), radius(radius), corner_point_count(corner_point_count)
{
  update();
}

void RoundedRect::set_size(const sf::Vector2f &s)
{
  this->size = s;
  update();
}

void RoundedRect::set_corners_radius(float r)
{
  this->radius = r;
  update();
}

void RoundedRect::set_corner_point_count(unsigned int c)
{
  this->corner_point_count = c;
  update();
}

std::size_t RoundedRect::getPointCount() const
{
  return corner_point_count * 4;
}

sf::Vector2f RoundedRect::getPoint(std::size_t index) const
{
  if (index >= corner_point_count * 4)
    return {0, 0};

  float delta_angle = 90.0f / (corner_point_count - 1);
  sf::Vector2f center;
  unsigned int center_index = index / corner_point_count;
  static const float pi = 3.141592654f;

  switch (center_index)
  {
  case 0:
    center.x = size.x - radius;
    center.y = radius;
    break;
  case 1:
    center.x = radius;
    center.y = radius;
    break;
  case 2:
    center.x = radius;
    center.y = size.y - radius;
    break;
  case 3:
    center.x = size.x - radius;
    center.y = size.y - radius;
    break;
  }

  return sf::Vector2f(
      radius * cos(delta_angle * (index - center_index) * pi / 180) + center.x,
      -radius * sin(delta_angle * (index - center_index) * pi / 180) +
          center.y);
}
