#include "enemy.h"
#include <cmath>
#include <random>

Enemy::Enemy(Resources &r) : resources(r), gui(r)
{
  regenerate(StageName::GREEN_FOREST, 1, false);
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
  this->level = lv;
  gui.set_info(n, lv);
}

void Enemy::set_regenerating(bool r)
{
  regenerating = r;
}

void Enemy::receive_damage(const double &damage_received)
{
  set_hp(hp - damage_received);
  if (hp <= 0)
  {
    set_hp(0);
    dead = true;
  }
}

void Enemy::set_texture(const sf::Texture &texture)
{
  sprite.setTexture(texture, true);
  sprite.setOrigin(sprite.getLocalBounds().width / 2,
                   sprite.getLocalBounds().height /
                       (2 * std::pow(sprite.getLocalBounds().height, -0.082)));
  sprite.setPosition(1095.0f, 760.0f);
  sprite.setScale(0.8f, 0.8f);
}

void Enemy::regenerate(const StageName &stage_name, const int &min_level,
                       const bool &is_boss)
{
  dead = false;
  regenerating = false;
  auto random_enemy = generator.get_random_enemy(stage_name);

  // Uses the Mersenne Twister PRNG to generate a random integer from the
  // interval [min_level, min_level + 2].
  static std::random_device random_device;
  static std::mt19937 rng(random_device());
  std::uniform_int_distribution<std::mt19937::result_type> dist(min_level,
                                                                min_level + 2);
  level = static_cast<int>(dist(rng));

  const int damage_multiplier = [&] { return is_boss ? 20 : 1; }();
  const int hp_multiplier = [&] { return is_boss ? 5 : 1; }();
  const int xp_held_multiplier = [&] { return is_boss ? 3 : 1; }();

  damage = (base_damage * damage_multiplier) * pow(1.045, level);
  xp_held = ((base_xp_held * xp_held_multiplier)) * pow(1.08, level);
  set_max_hp((base_max_hp * hp_multiplier) * pow(1.12, level));
  set_hp(max_hp);
  set_texture(resources.get_texture(random_enemy));
  set_info(resources.get_name(random_enemy), level);
}

bool &Enemy::is_dead()
{
  return dead;
}

bool &Enemy::is_regenerating()
{
  return regenerating;
}

double &Enemy::get_xp_held()
{
  return xp_held;
}

double &Enemy::get_damage()
{
  return damage;
}