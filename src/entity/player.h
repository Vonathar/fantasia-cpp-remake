#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../clickable.h"
#include <iostream>
using std::string;

class Player : public sf::Clickable
{
  public:
  Player() = default;
  ~Player() override = default;
  string name{};
  int level{};
  float hp{};
  float max_hp{};
  float xp{};
  float required_xp{};
  void click() override;
  void increase_level();
};

#endif //_PLAYER_H_
