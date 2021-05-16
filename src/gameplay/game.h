#ifndef _GAME_H_
#define _GAME_H_

#include "../entity/enemy.h"
#include "../entity/player.h"
#include "../entity/stage.h"
#include "../resource_manager.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

class Game
{
  public:
  ResourceManager resource_manager{};
  Enemy enemy{};
  Player player{};
  Stage stage{};

  private:
  sf::RenderWindow *window;
  void run();
  void process_event(sf::Event event);
  void update();
  void render();
};

#endif //_GAME_H_
