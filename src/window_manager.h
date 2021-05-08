#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

#include "SFML/Graphics.hpp"
#include "resource_manager.h"

class WindowManager {

 public:
  /**
   * Draws all managed resources to the window, ready to be painted by the next
   * call to display.
   */
  void draw_all ();
  /**
   * Starts the main window and the game loop.
   */
  void start_window ();

 private:
  ResourceManager resource_manager;
  sf::RenderWindow window{sf::VideoMode (1920, 1080, 32), "Fantasia"};
};

#endif//_WINDOW_MANAGER_H_
