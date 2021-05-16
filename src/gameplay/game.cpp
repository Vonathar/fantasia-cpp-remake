#include "game.h"

void Game::run()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  window = new sf::RenderWindow(sf::VideoMode(1920, 1080, 32), "Fantasia",
                                sf::Style::Default, settings);

  while (window->isOpen())
  {
    sf::Event event{};
    while (window->pollEvent(event))
    {
      process_event(event);
    }
    // Draw everything
  }
}

void Game::process_event(sf::Event event)
{
  if (event.type == sf::Event::Closed)
  {
    window->close();
  }
  if (event.type == sf::Event::MouseButtonPressed)
  {
    sf::Vector2f click_pos(static_cast<float>(event.mouseButton.x),
                           static_cast<float>(event.mouseButton.y));
    // Process click
  }
}
