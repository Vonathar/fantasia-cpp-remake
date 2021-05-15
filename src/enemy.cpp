#include "enemy.h"

void Enemy::click ()
{
  std::cout << "Clicked enemy." << std::endl;
  std::cout << "Level: " << this->level << std::endl;
}
void Enemy::set_name (const string &name)
{
  Enemy::name = name;
}
void Enemy::set_level (int level)
{
  Enemy::level = level;
}
void Enemy::set_hp (float hp)
{
  Enemy::hp = hp;
}
string Enemy::get_name () const
{
  return name;
}
int Enemy::get_level () const
{
  return level;
}
float Enemy::get_hp () const
{
  return hp;
}
