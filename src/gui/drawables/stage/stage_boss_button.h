#ifndef FANTASIA_REMAKE_STAGE_BOSS_BUTTON_H_
#define FANTASIA_REMAKE_STAGE_BOSS_BUTTON_H_

#include "../../../interfaces/clickable.h"
#include "../../resources.h"
#include "../reusable/rounded_rect.h"
#include <SFML/Graphics.hpp>

class StageBossButton : public sf::Drawable, public Clickable
{

  public:
  explicit StageBossButton(Resources &r);
  bool boundaries_contain(sf::Vector2f &pos) override;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void set_boss_available();
  void set_boss_active();
  void set_visible(bool v);
  sf::FloatRect get_bounds();

  private:
  Resources &resources;
  RoundedRect rect{};
  sf::Text text{};
  bool visible;
};

#endif // FANTASIA_REMAKE_STAGE_BOSS_BUTTON_H_