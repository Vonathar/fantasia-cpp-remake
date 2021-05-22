#include "player.h"

Player::Player(Resources &r) : resources(r), gui(r)
{
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
  this->level++;
  for (const auto &req : rank.requirements)
  {
    if (req.first > this->level)
    {
      rank.name = req.second;
      break;
    }
  }
  gui.set_info(rank.name, this->level);
}

void Player::set_hp(double n)
{
  this->hp = n;
  gui.set_hp(n);
}

void Player::set_max_hp(double n)
{
  this->max_hp = n;
  gui.set_max_hp(n);
}

void Player::set_xp(double n)
{
  this->xp = n;
  gui.set_xp(n);
}

void Player::set_required_xp(double n)
{
  this->required_xp = n;
  gui.set_required_xp(n);
}

void Player::set_fever(double n)
{
  this->fever = n;
  gui.set_fever(n);
}
