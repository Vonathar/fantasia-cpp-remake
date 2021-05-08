#include "window_manager.h"

void WindowManager::draw_all ()
{
  window.draw (resource_manager.get_background_sprite ());
  window.draw (resource_manager.get_battle_area_sprite ());
  window.draw (resource_manager.get_player_sprite ());
  window.draw (resource_manager.get_player_info ());
  window.display ();
}

void WindowManager::start_window ()
{
  resource_manager.initialise_window ();
  while (window.isOpen ())
  {
	sf::Event e{};
	while (window.pollEvent (e))
	{
	  if (e.type == sf::Event::Closed)
	  {
		window.close ();
	  }
	}
	draw_all ();
  }
}
