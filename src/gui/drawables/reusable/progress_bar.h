#ifndef _PROGRESS_BAR_H_
#define _PROGRESS_BAR_H_

#include "rounded_rect.h"

class ProgressBar : public sf::Drawable
{

  public:
  ProgressBar(float width, sf::Color fg_color, float pos_x, float pos_y);
  void set_value(float v);
  void set_max_value(float max_v);

  private:
  RoundedRect background_rect{};
  RoundedRect foreground_rect{};
  float width;
  float value{0};
  float max_value{0};
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void refresh();
};
#endif //_PROGRESS_BAR_H_
