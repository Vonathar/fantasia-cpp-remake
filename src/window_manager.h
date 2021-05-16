#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

#include "SFML/Graphics.hpp"
#include "resource_manager.h"

class WindowManager
{
  public:
  WindowManager(ResourceManager *resource_manager, Player *player, Enemy *enemy,
                Stage *stage);
  /**
   * Draws all managed resources to the window, ready to be painted by the next
   * call to display.
   */
  void draw_all();
  /**
   * Starts the main window and the game loop.
   */
  void start_window();

  private:
  ResourceManager *resource_manager_;
  sf::RenderWindow *window_;
  Player *player_;
  Enemy *enemy_;
  Stage *stage_;
  std::vector<std::pair<sf::FloatRect, sf::Clickable *>> get_bound_pairs();
  void handle_click(sf::Event event);
};

#endif //_WINDOW_MANAGER_H_
