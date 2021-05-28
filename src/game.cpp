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
    process_click(event);
  }
}

void Game::process_click(sf::Event event)
{
  sf::Vector2f click_pos(static_cast<float>(event.mouseButton.x),
                         static_cast<float>(event.mouseButton.y));
  if (enemy.get_sprite().getGlobalBounds().contains(click_pos))
  {
    if (enemy.is_regenerating())
    {
      return;
    }
    if (!enemy.is_dead())
    {
      animator.set_clicked_state(enemy.get_sprite());
      animator.add_damage_bubble(player.get_click_damage());
      enemy.receive_damage(player.get_click_damage());
    }
    if (enemy.is_dead())
    {
      animator.set_dead_state(enemy.get_sprite());
      player.receive_xp(enemy.get_xp_held());
      player.set_hp(player.get_max_hp());
    }
  }
}

void Game::update()
{
  if (clock.getElapsedTime().asMilliseconds() >= 1000)
  {
    if (!player.is_regenerating())
      player.receive_damage(enemy.get_damage());

    if (player.is_dead() && !player.is_regenerating())
      animator.set_dead_state(player.get_sprite());

    clock.restart();
  }

  if (player.is_regenerating() || enemy.is_regenerating())
    clock.restart();
}

void Game::render()
{
  this->window->clear();
  stage.render(*window);
  static_gui.render(*window);
  player.render(*window);
  enemy.render(*window);
  animator.animate();
  this->window->display();
}