#include "game.h"

void Game::start ()
{
  resource_manager.load_enemy_sprite (stage.get_stage (), enemy.get_name ());
  window_manager.start_window ();
}