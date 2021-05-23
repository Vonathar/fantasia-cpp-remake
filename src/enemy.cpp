#include "enemy.h"
#include <cmath>
#include <random>

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

void Enemy::regenerate(const StageName &stage_name, const int &min_level,
                       const bool &is_boss)
{
  auto random_enemy = generator.get_random_enemy(stage_name);

  // Uses the Mersenne Twister PRNG to generate a random integer from the
  // interval [min_level, min_level + 2]
  static std::random_device random_device;
  static std::mt19937 rng(random_device());
  std::uniform_int_distribution<std::mt19937::result_type> dist(min_level,
                                                                min_level + 2);
  level = static_cast<int>(dist(rng));

  const int damage_multiplier = [&] { return is_boss ? 20 : 1; }();
  const int hp_multiplier = [&] { return is_boss ? 5 : 1; }();

  damage = (base_damage * damage_multiplier) * pow(1.045, level);
  set_max_hp((base_max_hp * hp_multiplier) * pow(1.12, level));
  set_hp(max_hp);
  set_texture(resources.get_texture(random_enemy));
  set_info(resources.get_name(random_enemy), level);
}
