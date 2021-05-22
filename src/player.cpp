#include "player.h"
#include <cmath>

Player::Player(Resources &r) : resources(r), gui(r)
{
  set_hp(base_max_hp);
  set_max_hp(base_max_hp);
  set_required_xp(base_required_xp);
  set_xp(0);
  set_fever(0);
  rank.name = "Rogue";
  level = 1;
  click_damage = base_click_damage;
  gui.set_info(rank.name, level);
  sprite.setTexture(resources.get_texture(ResourceName::PLAYER_TEXTURE));
  sprite.setPosition(655.0f, 680.0f);
  sprite.setScale(0.6f, 0.6f);
}

void Player::render(sf::RenderTarget &target)
{
  target.draw(sprite);
  gui.render(target);
}

sf::Sprite &Player::get_sprite()
{
  return sprite;
}

void Player::increment_level()
{
  level++;
  set_xp(xp - required_xp);
  set_required_xp(base_required_xp * pow(1.1, level));
  set_max_hp(base_max_hp * pow(1.05, max_hp));
  set_hp(max_hp);

  for (const auto &req : rank.requirements)
  {
    if (req.first > level)
    {
      rank.name = req.second;
      break;
    }
  }
  gui.set_info(rank.name, level);
}

void Player::set_hp(const double &n)
{
  hp = n;
  gui.set_hp(n);
}

void Player::set_max_hp(const double &n)
{
  max_hp = n;
  gui.set_max_hp(n);
}

void Player::set_xp(const double &n)
{
  xp = n;
  gui.set_xp(n);
}

void Player::set_required_xp(const double &n)
{
  required_xp = n;
  gui.set_required_xp(n);
}

void Player::set_fever(const double &n)
{
  fever = n;
  gui.set_fever(n);
}

double &Player::get_click_damage()
{
  return click_damage;
}
