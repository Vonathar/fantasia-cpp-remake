#include "enemy.h"
#include <cmath>

Enemy::Enemy(Resources &r) : resources(r), gui(r)
{
  regenerate(StageName::GREEN_FOREST, 1);
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

void Enemy::set_hp(const double &n)
{
  this->hp = n;
  gui.set_hp(n);
}

void Enemy::set_max_hp(const double &n)
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

void Enemy::receive_damage(const double &damage_received)
{
  set_hp(hp - damage_received);
  regenerate(StageName::GREEN_FOREST, 1);
}

void Enemy::set_texture(const sf::Texture &texture)
{
  sprite.setTexture(texture, true);
  sprite.setPosition(1095.0f - (static_cast<float>(texture.getSize().x) / 2.0f),
                     740.0f - (static_cast<float>(texture.getSize().y) / 2.0f));
  sprite.setScale(0.8f, 0.8f);
}

void Enemy::regenerate(const StageName &stage_name, const int &min_level)
{
  auto random_enemy = generator.get_random_enemy(stage_name);
  set_texture(resources.get_texture(random_enemy));
  // TODO: Randomise the enemy level between min_level and min_level + 2
  level = min_level;
  damage = base_damage * pow(1.045, level);
  set_max_hp(base_max_hp * pow(1.12, level));
  set_hp(max_hp);
  set_info(resources.get_name(random_enemy), min_level);
}
