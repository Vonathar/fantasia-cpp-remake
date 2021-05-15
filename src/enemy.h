#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "clickable.h"
#include <iostream>

using std::string;

class Enemy : public sf::Clickable {

 public:
  Enemy () = default;
  ~Enemy () override = default;
  void set_name (const string &name);
  void set_level (int level);
  void set_hp (float hp);
  void click () override;
  string get_name () const;
  int get_level () const;
  float get_hp () const;

 private:
  string name{};
  int level{};
  float hp{};
};

#endif//_ENEMY_H_
