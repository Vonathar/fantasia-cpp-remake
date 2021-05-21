#include "game.h"

void Game::run()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080, 32),
                                              "Fantasia", sf::Style::Fullscreen,
                                              settings);
  while (window->isOpen())
  {
    sf::Event event{};
    while (window->pollEvent(event))
    {
      process_event(event);
    }
    update();
    render();
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
    // TODO: Process click
  }
}

void Game::update() {}

void Game::render()
{
  this->window->clear();
  animator.animate();
  stage.render(*window);
  static_gui.render(*window);
  player.render(*window);
  enemy.render(*window);
  this->window->display();
}