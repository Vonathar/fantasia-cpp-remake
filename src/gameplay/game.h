#ifndef _GAME_H_
#define _GAME_H_

#include "../enemy.h"
#include "../player.h"
#include "../resource_manager.h"
#include "../stage.h"
#include "../window_manager.h"
#include <iostream>
#include <vector>

class Game {

 public:
  Enemy enemy{};
  Player player{};
  Stage stage{};
  ResourceManager resource_manager{};
  WindowManager window_manager{&resource_manager, &player, &enemy, &stage};
  void start ();
};

#endif//_GAME_H_
