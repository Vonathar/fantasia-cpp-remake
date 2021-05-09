#include "window_manager.h"

void WindowManager::draw_all ()
{
  for (auto drawable : resource_manager.get_drawables ())
  {
	window->draw (*drawable);
  }
  window->display ();
}

void WindowManager::start_window ()
{
  resource_manager.initialise_window ();
  while (window->isOpen ())
  {
	sf::Event e{};
	while (window->pollEvent (e))
	{
	  if (e.type == sf::Event::Closed)
	  {
		window->close ();
	  }
	}
	draw_all ();
  }
}

WindowManager::WindowManager ()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  window = new sf::RenderWindow (sf::VideoMode (1920, 1080, 32), "Fantasia",
								 sf::Style::Default, settings);
}
