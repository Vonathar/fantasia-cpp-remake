#include "enemy.h"

Enemy::Enemy(Resources &r) : resources(r), gui(r)
{
  sf::Texture &texture = resources.get_texture(EnemyName::FAIRY_FILIA);
  sprite.setTexture(texture);
  sprite.setPosition(1095.0f - (static_cast<float>(texture.getSize().x) / 2.0f),
                     740.0f - (static_cast<float>(texture.getSize().y) / 2.0f));
  sprite.setScale(0.8f, 0.8f);
}

void Enemy::render(sf::RenderTarget &target)
{
  target.draw(sprite);
  gui.render(target);
}

sf::Sprite &Enemy::get_sprite()
{
  return sprite;
}
