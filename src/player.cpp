#include "player.h"

void Player::click ()
{
  std::cout << "Clicked player." << std::endl;
  std::cout << "Level: " << this->level << std::endl;
}

void Player::increase_level ()
{
  this->level += this->level;
}
const string &Player::get_name () const
{
  return name;
}
void Player::set_name (const string &name)
{
  Player::name = name;
}
int Player::get_level () const
{
  return level;
}
void Player::set_level (int level)
{
  Player::level = level;
}
float Player::get_hp () const
{
  return hp;
}
void Player::set_hp (float hp)
{
  Player::hp = hp;
}
