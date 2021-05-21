#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_

#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <map>

class Animator
{
  public:
  Animator(std::unique_ptr<sf::RenderWindow> &w, sf::Sprite &player_sprite,
           sf::Sprite &enemy_sprite);
  void animate();

  private:
  std::unique_ptr<sf::RenderWindow> &window;
  std::map<sf::Sprite *, bool> animation_states;
  std::map<sf::Sprite *, sf::Vector2f> original_scales;
  void find_hovered_sprite();
  void update_scales();
};

#endif //_ANIMATOR_H_
