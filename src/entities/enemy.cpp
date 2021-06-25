#include "enemy.h"
#include <cmath>
#include <random>

Enemy::Enemy(Resources &r) : resources(r), gui(r)
{
  regenerate(StageName::GREEN_FOREST, 1, false);
}

void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(gui);
}

bool Enemy::is_sprite_in_bounds(sf::Vector2f &pos)
{
  return gui.boundaries_contain(pos);
}

sf::Sprite &Enemy::get_sprite()
{
  return gui.get_sprite();
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

void Enemy::regenerate(const StageName &stage_name, const int &min_level,
                       const bool &is_boss)
{
  EnemyName random_enemy = is_boss ? generator.get_random_boss(stage_name)
                                   : generator.get_random_enemy(stage_name);

  // Uses the Mersenne Twister PRNG to generate a random integer from the
  // interval [min_level, min_level + 2].
  static std::random_device random_device;
  static std::mt19937 rng(random_device());
  std::uniform_int_distribution<int> dist(min_level, min_level + 2);
  level = static_cast<int>(dist(rng));

  const int damage_multiplier = [&] { return is_boss ? 20 : 1; }();
  const int hp_multiplier = [&] { return is_boss ? 5 : 1; }();
  const int xp_held_multiplier = [&] { return is_boss ? 3 : 1; }();
  const int coins_held_multiplier = [&] { return is_boss ? 4 : 1; }();

  damage = (base_damage * damage_multiplier) * pow(1.045, level);
  xp_held = (base_xp_held * xp_held_multiplier) * pow(1.08, level);
  coins_held = (base_coins_held * coins_held_multiplier) * pow(1.05, level);
  set_max_hp((base_max_hp * hp_multiplier) * pow(1.12, level));
  set_hp(max_hp);
  gui.set_texture(resources.get_texture(random_enemy));
  set_info(resources.get_name(random_enemy), level);

  dead = false;
  regenerating = false;
  boss = is_boss;
}

bool &Enemy::is_dead()
{
  return dead;
}

bool &Enemy::is_regenerating()
{
  return regenerating;
}

bool &Enemy::is_boss()
{
  return boss;
}

double &Enemy::get_xp_held()
{
  return xp_held;
}

double &Enemy::get_coins_held()
{
  return coins_held;
}

double &Enemy::get_damage()
{
  return damage;
}