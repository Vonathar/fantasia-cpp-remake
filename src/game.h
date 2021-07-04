#ifndef _GAME_H_
#define _GAME_H_

#include "SFML/Graphics.hpp"
#include "entities/enemy.h"
#include "entities/inventory.h"
#include "entities/player.h"
#include "entities/stage.h"
#include "gui/animator.h"
#include "gui/drawables/stage/stage_gui.h"
#include "gui/drawables/static_gui.h"
#include "gui/resources.h"
#include <iostream>
#include <vector>

class Game
{
  public:
  void run();

  private:
  sf::Clock clock{};
  std::unique_ptr<sf::RenderWindow> window{};
  Resources resources{};
  StaticGUI static_gui{resources};
  Inventory inventory{resources};
  Player player{resources};
  Enemy enemy{resources};
  Stage stage{resources};
  Animator animator{window, resources, inventory, player, enemy, stage};

  void process_event(sf::Event event);
  void process_click(sf::Event event);
  void handle_boss_button_click();
  void handle_next_level_click();
  void process_player_attacked();
  void handle_enemy_click();
  void process_enemy_death();
  void update();
  void render();
};

#endif //_GAME_H_
