#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "../clickable.h"
#include <iostream>

using std::string;

struct Enemy : public sf::Clickable {

 public:
  Enemy () = default;
  ~Enemy () override = default;
  string name{};
  int level{};
  float hp{};
  float max_hp{};
  void click () override;
};

#endif//_ENEMY_H_
