#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "clickable.h"
#include <iostream>

using std::string;

class Player : public sf::Clickable {

 public:
  Player (){};
  ~Player (){};
  const string &get_name () const;
  void set_name (const string &name);
  int get_level () const;
  void set_level (int level);
  float get_hp () const;
  void set_hp (float hp);
  string name{};
  int level{};
  float hp{};
  void click () override;

 private:
  void increase_level ();
};

#endif//_PLAYER_H_
