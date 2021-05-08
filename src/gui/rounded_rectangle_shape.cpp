#include "rounded_rectangle_shape.h"
#include <cmath>

namespace sf
{
RoundedRectangleShape::RoundedRectangleShape (const Vector2f &size,
											  float radius,
											  unsigned int corner_point_count)
	: size (size), radius (radius), corner_point_count (corner_point_count)
{
  update ();
}

void RoundedRectangleShape::set_size (const Vector2f &size)
{
  this->size = size;
  update ();
}

void RoundedRectangleShape::set_corners_radius (float radius)
{
  this->radius = radius;
  update ();
}

void RoundedRectangleShape::set_corner_point_count (unsigned int count)
{
  this->corner_point_count = count;
  update ();
}

std::size_t RoundedRectangleShape::getPointCount () const
{
  return corner_point_count * 4;
}

sf::Vector2f RoundedRectangleShape::getPoint (std::size_t index) const
{
  if (index >= corner_point_count * 4)
	return sf::Vector2f (0, 0);

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

  return sf::Vector2f (
	  radius * cos (delta_angle * (index - center_index) * pi / 180) + center.x,
	  -radius * sin (delta_angle * (index - center_index) * pi / 180)
		  + center.y);
}
}// namespace sf
