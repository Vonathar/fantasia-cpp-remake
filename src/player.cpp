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
