#ifndef _STAGE_ENEMY_COUNTER_H_
#define _STAGE_ENEMY_COUNTER_H_

#include "../../resources.h"
#include <SFML/Graphics.hpp>

class StageEnemyCounter : public sf::Drawable
{
  public:
  explicit StageEnemyCounter(Resources &r);
  void set_enemies_killed(int n);
  void set_visible(bool v);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  private:
  bool visible;
  Resources &resources;
  sf::Sprite sprite{};
  sf::Text text{};
};

#endif // _STAGE_ENEMY_COUNTER_H_
