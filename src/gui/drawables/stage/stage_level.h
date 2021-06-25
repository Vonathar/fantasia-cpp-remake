#ifndef _STAGE_LEVEL_H_
#define _STAGE_LEVEL_H_

#include "../../../enums/stage_level_status.h"
#include "../../resources.h"
#include "../reusable/rounded_rect.h"
#include <SFML/Graphics.hpp>

class StageLevel : public sf::Drawable
{
  public:
  StageLevel(Resources &r, int level, float x, float y);
  const float posX;
  const float posY;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void increment_value();
  sf::FloatRect get_bounds();
  void set_status(StageLevelStatus s);
  int get_value() const;
  StageLevelStatus get_status();

  private:
  StageLevelStatus status;
  Resources &resources;
  sf::Text text{};
  RoundedRect rect{};
  int value{};
  void set_text(std::string t);
};

#endif // _STAGE_LEVEL_H_
