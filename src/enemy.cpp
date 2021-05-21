#include "enemy.h"

Enemy::Enemy(Resources &r) : resources(r), gui(r)
{
  sprite.setTexture(resources.get_enemy_texture(EnemyName::FAIRY_FILIA));
  sprite.setPosition(1040.0f, 650.0f);
  sprite.setScale(0.9f, 0.9f);
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
