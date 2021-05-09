#ifndef _PROGRESS_BAR_H_
#define _PROGRESS_BAR_H_

#include "rounded_rectangle_shape.h"

namespace sf
{
/**
 * A class that represents a progress bar that can be drawn on the window.
 */
class ProgressBar : public Drawable {

 public:
  ProgressBar (float width, sf::Color fg_color, float pos_x, float pos_y);
  void set_value (float value);
  void set_max_value (float max_value);

 private:
  RoundedRectangleShape background_rect{};
  RoundedRectangleShape foreground_rect{};
  float width;
  float value{0};
  float max_value{0};
  sf::Color fg_color;
  void draw (RenderTarget &target, RenderStates states) const override;
  void refresh ();
};
}// namespace sf
#endif//_PROGRESS_BAR_H_
