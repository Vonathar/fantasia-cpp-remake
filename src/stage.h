#ifndef _STAGE_H_
#define _STAGE_H_

#include "SFML/Graphics.hpp"
#include "entity.h"
#include "resources.h"
#include "stage_name.h"

class Stage : public Entity
{
  public:
  explicit Stage(Resources &r);
  void render(sf::RenderTarget &target) override;

  private:
  Resources &resources;
  StageName name{StageName::GREEN_FOREST};
  bool can_advance{false};
  int kills_to_advance{10};
  sf::Sprite sprite{};
};

#endif //_STAGE_H_
