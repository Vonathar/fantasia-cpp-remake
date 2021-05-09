#include "progress_bar.h"
#include "SFML/Graphics.hpp"

namespace sf
{

ProgressBar::ProgressBar (float width, sf::Color fg_color, float pos_x,
						  float pos_y)
	: width (width), fg_color (fg_color)
{
  background_rect.set_size (sf::Vector2f (width, 11));
  foreground_rect.set_size (sf::Vector2f (width, 11));
  background_rect.setPosition (pos_x, pos_y);
  foreground_rect.setPosition (pos_x, pos_y);
  background_rect.set_corners_radius (5);
  foreground_rect.set_corners_radius (5);
  background_rect.set_corner_point_count (5);
  foreground_rect.set_corner_point_count (5);
  background_rect.setFillColor (sf::Color (189, 192, 185));
  foreground_rect.setFillColor (fg_color);
}

void ProgressBar::set_max_value (float max_value)
{
  this->max_value = max_value;
  refresh ();
}

void ProgressBar::set_value (float value)
{
  this->value = value;
  refresh ();
}

void ProgressBar::draw (RenderTarget &target, RenderStates states) const
{
  target.draw (background_rect);
  target.draw (foreground_rect);
}

void ProgressBar::refresh ()
{
  float fg_width = (value / max_value) * width;
  foreground_rect.set_size (Vector2f (fg_width, 11));
}

}// namespace sf