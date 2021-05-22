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

void Enemy::set_hp(const float &n)
{
  this->hp = n;
  gui.set_hp(n);
}

void Enemy::set_max_hp(const float &n)
{
  this->max_hp = n;
  gui.set_max_hp(n);
}
void Enemy::set_info(const std::string &n, const int &lv)
{
  this->name = n;
  this->level = lv;
  gui.set_info(n, lv);
}
