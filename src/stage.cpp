#include "stage.h"

Stage::Stage(Resources &r) : resources(r)
{
  sprite.setPosition(0, 0);
  sprite.setScale(1.0f, 1.0f);
  sprite.setTexture(resources.get_texture(StageName::GREEN_FOREST));
}

void Stage::render(sf::RenderTarget &target)
{
  target.draw(sprite);
}